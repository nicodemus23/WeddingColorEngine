// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ColorMath.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeColorMath() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
UPackage* Z_Construct_UPackage__Script_WeddingColorEngine();
WEDDINGCOLORENGINE_API UClass* Z_Construct_UClass_UColorMath();
WEDDINGCOLORENGINE_API UClass* Z_Construct_UClass_UColorMath_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UColorMath ***************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UColorMath;
UClass* UColorMath::GetPrivateStaticClass()
{
	using TClass = UColorMath;
	if (!Z_Registration_Info_UClass_UColorMath.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ColorMath"),
			Z_Registration_Info_UClass_UColorMath.InnerSingleton,
			StaticRegisterNativesUColorMath,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UColorMath.InnerSingleton;
}
UClass* Z_Construct_UClass_UColorMath_NoRegister()
{
	return UColorMath::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UColorMath_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "ColorMath.h" },
		{ "ModuleRelativePath", "Public/ColorMath.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UColorMath constinit property declarations *******************************
// ********** End Class UColorMath constinit property declarations *********************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UColorMath>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UColorMath_Statics
UObject* (*const Z_Construct_UClass_UColorMath_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_WeddingColorEngine,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UColorMath_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UColorMath_Statics::ClassParams = {
	&UColorMath::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UColorMath_Statics::Class_MetaDataParams), Z_Construct_UClass_UColorMath_Statics::Class_MetaDataParams)
};
void UColorMath::StaticRegisterNativesUColorMath()
{
}
UClass* Z_Construct_UClass_UColorMath()
{
	if (!Z_Registration_Info_UClass_UColorMath.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UColorMath.OuterSingleton, Z_Construct_UClass_UColorMath_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UColorMath.OuterSingleton;
}
UColorMath::UColorMath(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UColorMath);
UColorMath::~UColorMath() {}
// ********** End Class UColorMath *****************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_nleac_OneDrive___Warner_Bros__Discovery_Documents_Unreal_Projects_WeddingColorEngine_Source_WeddingColorEngine_Public_ColorMath_h__Script_WeddingColorEngine_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UColorMath, UColorMath::StaticClass, TEXT("UColorMath"), &Z_Registration_Info_UClass_UColorMath, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UColorMath), 1658851005U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_nleac_OneDrive___Warner_Bros__Discovery_Documents_Unreal_Projects_WeddingColorEngine_Source_WeddingColorEngine_Public_ColorMath_h__Script_WeddingColorEngine_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_nleac_OneDrive___Warner_Bros__Discovery_Documents_Unreal_Projects_WeddingColorEngine_Source_WeddingColorEngine_Public_ColorMath_h__Script_WeddingColorEngine_2229206131{
	TEXT("/Script/WeddingColorEngine"),
	Z_CompiledInDeferFile_FID_Users_nleac_OneDrive___Warner_Bros__Discovery_Documents_Unreal_Projects_WeddingColorEngine_Source_WeddingColorEngine_Public_ColorMath_h__Script_WeddingColorEngine_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_nleac_OneDrive___Warner_Bros__Discovery_Documents_Unreal_Projects_WeddingColorEngine_Source_WeddingColorEngine_Public_ColorMath_h__Script_WeddingColorEngine_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
