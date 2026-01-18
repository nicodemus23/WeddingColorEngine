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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Palette")
	EPaletteMode Mode = EPaletteMode::Analogous;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Palette", meta = (ClampMin = "1", ClampMax = "100"))
	int32 Count = 8;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Palette", meta = (UIMin = "0.0", UIMax = "360.0"))
	float BaseHueDeg = 35.0f; // terracotta-ish

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Palette")
	float HueSpreadDeg = 25.f; // earth-tone friendly

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Palette", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float TargetL = 0.72f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Palette")
	float LVariance = 0.03f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Palette", meta = (ClampMin = "0.0"))
	float TargetC = 0.08f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Palette")
	float CVariance = 0.02f;
};


