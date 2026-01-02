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
	// Expose the Oklab conversion to Blueprint for UI visualization
	UFUNCTION(BlueprintPure)
	static FVector LinearToOklab(FLinearColor LinColor);

	UFUNCTION(BlueprintPure)
	static FLinearColor OklabToLinear(FVector Lab);

	UFUNCTION(BlueprintPure)
	static float GetPerceptualDistance(FLinearColor ColorA, FLinearColor ColorB);
	
};
