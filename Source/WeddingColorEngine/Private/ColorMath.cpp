// Fill out your copyright notice in the Description page of Project Settings.


#include "ColorMath.h"
// In the Oklab color space derivation by Björn Ottosson, M1 and M2 refer to the two primary transformation matrices 
// used to convert colors between physical light(RGB) and perceptual coordinates(L, a, b).The transformation is a two - step 
// linear process separated by a non - linear "power law" step(the cube root) that mimics how human nerves compress light signals.
// 
// M1 & M2 refer to the two primary transformation matrices used to convert 
// colors between physical light (RGB) and perceptual coordinates (L, a, b)
// 
// M1: Cone response matrix 
//      This matrix transforms Linear sRGB into LMS space (Long, Medium, Short wavelengths). 
//      It essentially "sorts" the light into the intensities that the three types of cones 
//      in the human eye actually respond to.
// 
// Non-Linearity: Take the cube root (sqrt[3]{x}) of the LMS values. This is based on the 
//      observation that human perception of brightness is roughly a power function
// 
// M2: Lab projection matrix - takes perceived cone responses and projects onto 3 axes: 
//      - L (Lightness)
//      - a (green, red)
//      - b (blue, yellow)
// 
// Inverse Transform: (Oklab -> RGB) = M1^-1 and M2^2
// Steps: 
//      1. Inverse M2(Lab->LMS) = Converts the abstract perceptual coordinates back into the 
//         compressed cone responses. The coefficients (like 0.3963377774f) are the result of inverting the M2 matrix.
// 
//      2. Revert Non-Linearity = Raise the values to the power of 3 to undo the cube root
// 
//      3. Inverse M1 (LMS->RGB) This final step converts the cone responses back into the actual 
//          Red, Green, and Blue intensities that Unreal Engine needs to drive the display or shader. The coefficients 
//          here (like 4.0767416621f) are the inverted M1 matrix values.
// 
// Overall, this achieves:
// Accuracy: Without M1, you wouldn't be accounting for the fact that human eyes are far more sensitive to Green light than Blue.
// 
// Uniformity: Without M2, rotating the "Hue" of a bridesmaid dress would cause the dress to look either much brighter or much 
//          darker in the 3D scene, even if the math said they were the same "intensity."Millcreek Lighting: Because these matrices 
//          are calibrated to the D65 White Point (standard daylight), they will remain mathematically accurate as adjustments are made in 
//          UE5.7 SunSky and Skylight to mimic the specific lighting conditions of the September 18th wedding date.
// 
// 

// Summary: 
//		Matrices based on Bjorn Ottosson's Oklab implementation.
//		M1: Linear sRGB -> LMS
//		M2: LMS -> Oklab


/**
 * FORWARD TRANSFORM: Linear sRGB -> Oklab
 * Do this to take Display Colors and turn them into "Human Colors."
 */
FVector UColorMath::LinearToOklab(const FLinearColor& LinColor)
{
	// M1 Matrix: Linear sRGB to LMS
	/** * M1: The Cone Response Matrix.
	 * Since our eyes are more sensitive to Green (G) than Blue (B), these weights
	 * "normalize" the RGB signal into what our Long, Medium, and Short cones see.
	 */

	// Linear sRGB -> LMS (Cone Response)
	float l = 0.4122214708f * LinColor.R + 0.5363325363f * LinColor.G + 0.0514459929f * LinColor.B;
	float m = 0.2119034982f * LinColor.R + 0.6806995451f * LinColor.G + 0.1073969566f * LinColor.B;
	float s = 0.0883024619f * LinColor.R + 0.2817188376f * LinColor.G + 0.6299787005f * LinColor.B;

	/**
	 * PERCEPTUAL COMPRESSION:
	 * Human nerves don't process light linearly. Taking the cube root mimics how
	 * our brain "compresses" brightness so that we can see detail in both shadows and highlights.
	 * FMath::Max(val, 0.0f) prevents the math from crashing on negative light values.
	 */

	//  Non-linearity (Cube Root)
    //  Use FMath::Max(val, 0.0f) to prevent NaNs on negative values (though rare in Linear sRGB)
	float l_ = FMath::Pow(FMath::Max(l, 0.0f), 1.0f / 3.0f);
	float m_ = FMath::Pow(FMath::Max(m, 0.0f), 1.0f / 3.0f);
	float s_ = FMath::Pow(FMath::Max(s, 0.0f), 1.0f / 3.0f);

	// M2 Matrix: LMS -> Lab
	/**
	 * M2: Lab Projection.
	 * This plots the cone signals onto three axes:
	 * X = L (Brightness), Y = a (Green-to-Red contrast), Z = b (Blue-to-Yellow contrast).
	 */

	// LMS -> Oklab (Projection)
	return FVector(
		0.2104542553f * l_ + 0.7936177850f * m_ - 0.0040720468f * s_,
		1.9779984951f * l_ - 2.4285922050f * m_ + 0.4505937099f * s_,
		0.0259040371f * l_ + 0.7827717662f * m_ - 0.8086757660f * s_
	);
}

/**
 * INVERSE TRANSFORM: Oklab -> Linear sRGB
 * Do this to take our "Balanced" colors and turn them back into pixels Unreal can render.
 */
FLinearColor UColorMath::OklabToLinear(const FVector& Lab)
{

	/**
	 * INVERSE M2: Lab back to LMS.
	 * Converting abstract perceptual coordinates back into raw cone intensities.
	 */

	// Oklab -> LMS
	float l_ = Lab.X + 0.3963377774f * Lab.Y + 0.2158037573f * Lab.Z;
	float m_ = Lab.X - 0.1055613458f * Lab.Y - 0.0638541728f * Lab.Z;
	float s_ = Lab.X - 0.0894841775f * Lab.Y - 1.2914855480f * Lab.Z;

	//2. Reverting Non-Linearity
	// Raise the values to the power of 3 to undo the cube root :
	/**
	 * REVERTING NON-LINEARITY:
	 * Raising to the power of 3 "un-does" the cube root performed earlier.
	 */

	// Revert Non-linearity (Cube)
	float l = l_ * l_ * l_;
	float m = m_ * m_ * m_;
	float s = s_ * s_ * s_;

	// Inverse M1 Transform: LMS -> Linear RGB
	/**
	 * INVERSE M1: LMS back to RGB.
	 * Returning the cone intensities to the raw Red, Green, and Blue light values
	 * that drive your screen or shader.
	 */

	// LMS -> Linear sRGB
	return FLinearColor(
		+4.0767416621f * l - 3.3077115913f * m + 0.2309699292f * s,
		-1.2684380046f * l + 2.6097574011f * m - 0.3413193965f * s,
		-0.0041960863f * l - 0.7034186147f * m + 1.7076147010f * s
	);
}

/**
 * PERCEPTUAL DISTANCE (Delta-E):
 * Since Oklab is "Uniform," the distance between two points in this space
 * matches how different a human perceives them to be.
 */
float UColorMath::GetPerceptualDistance(const FLinearColor& ColorA, const FLinearColor& ColorB)
{
	FVector LabA = LinearToOklab(ColorA);
	FVector LabB = LinearToOklab(ColorB);

	// Euclidean Distance = distance between two points in Oklab space
	return FVector::Dist(LabA, LabB);
}
