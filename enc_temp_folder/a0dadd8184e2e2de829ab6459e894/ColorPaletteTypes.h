#pragma once

#include "CoreMinimal.h"
#include "ColorPaletteTypes.generated.h"

UENUM(BlueprintType)
enum class EPaletteMode : uint8
{
	Analogous,// Colors close together on the color wheel. Good for cohesive sets. 
	Triadic,// Three evenly spaced colors on the color wheel. (120° apart) Groups of 3 colors.
	SplitComplementary,// Base hue plus two neighbors of its compliment (Base Hue + 180°). Hue Spread will drive the compliments. Groups of 3 colors.
	Monochrome_L,// Same hue, similar Chroma but varied Lightness. One family, different shades. 
	Tetradic// Two complementary pairs (a rectangle on the wheel). BaseHue, BaseHue + 90°, BaseHue + 180°, BaseHue + 270°. Groups of 4 colors. 
};

UENUM(BlueprintType)
enum class EWeddingTimePreset : uint8
{
	Noon,
	LateAfternoon,
	CanyonShade,   // “sun blocked but sky still bright”
	GoldenHour,
	BlueHour
};

USTRUCT(BlueprintType)
struct WEDDINGCOLORENGINE_API FPaletteSettings
{
	GENERATED_BODY()
	// How the colors are spaced around the color wheel. Establish design patterns. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Palette", meta=(DisplayName = "Palette Style"))
	EPaletteMode Mode = EPaletteMode::Analogous;
	// How many total colors you want generated. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Palette", meta = (ClampMin = "1", ClampMax = "100"))
	int32 Count = 8;
	// Starting hue to generate variance from. 0° (or 360°) = Purplish-Red/Magenta, 90° = Yellow/Yellow-Green, 180° = Green/Cyan-Green, 270° = Blue
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Palette", meta = (DisplayName = "Base Hue Degrees(Chosen Color)", UIMin = "0.0", UIMax = "360.0"))
	float BaseHueDeg = 35.0f; // terracotta-ish
	// How far the palette is allowed to wander away from the base hue within the chosen color mode. Small spread = more cohesive. Large spread = more variety.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Palette", meta=(DisplayName = "Hue Spread Degrees(Variety)"))
	float HueSpreadDeg = 25.f; // earth-tone friendly
	// How bright the colors are perceptually. Higher = lighter/pastel. Lower = richer/deeper.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Palette", meta = (DisplayName = "Target Lightness(Brightness)", ClampMin = "0.0", ClampMax = "1.0"))
	float TargetL = 0.72f;
	// How much the brightness is allowed to randomly set values per color. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Palette", meta = (DisplayName = "Lightness Variance(Brightness Variety)"))
	float LVariance = 0.03f;
	// How saturated or "colorful" the palette is. Low = dusty/pastel. High = richer/more saturated.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Palette", meta = (DisplayName = "Target Chroma(Saturation/Colorfulness)", ClampMin = "0.0"))
	float TargetC = 0.08f;
	// How much the colorfulness/saturation is allowed to vary per color. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Palette", meta=(DisplayName = "Chroma Variance(Random Saturation Variation)"))
	float CVariance = 0.02f;
	
};


