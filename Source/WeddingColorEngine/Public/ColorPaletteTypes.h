#pragma once

#include "CoreMinimal.h"
#include "ColorPaletteTypes.generated.h"

UENUM(BlueprintType)
enum class EPaletteMode : uint8
{
	Analogous,
	Triadic,
	SplitComplementary,
	Monochrome_L,
	Tetradic
};

USTRUCT(BlueprintType)
struct WEDDINGCOLORENGINE_API FPaletteSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPaletteMode Mode = EPaletteMode::Analogous;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Count = 8;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BaseHueDeg = 35.0f; // terracotta-ish

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HueSpreadDeg = 25.f; // earth-tone friendly

	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	float TargetL = 0.72f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	float LVariance = 0.03f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	float TargetC = 0.08f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	float CVariance = 0.02f;
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
