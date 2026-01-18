// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ColorMath.generated.h"

/**
 *
 */
UCLASS()
class WEDDINGCOLORENGINE_API UColorMath : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	// * Converts Linear sRGB to Oklab (L, a, b).
	// * Returns FVector where X=L, Y=a, Z=b.
	UFUNCTION(BlueprintPure, Category = "Wedding Color Engine|Math")
	static FVector LinearToOklab(const FLinearColor& LinColor);

	
	// * Converts Oklab (L, a, b) to Linear sRGB.
	// * Input FVector where X=L, Y=a, Z=b.
	UFUNCTION(BlueprintPure, Category = "Wedding Color Engine|Math")
	static FLinearColor OklabToLinear(const FVector& Lab);

	// * Calculates perceptual distance (Delta-E) in Oklab space.
	UFUNCTION(BlueprintPure, Category = "Wedding Color Engine|Math")
	static float GetPerceptualDistance(const FLinearColor& ColorA, const FLinearColor& ColorB);

};
