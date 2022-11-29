// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "AssetManagerMain.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class JOYWAYTESTTASK_API UAssetManagerMain : public UAssetManager
{
	GENERATED_BODY()

public:
	/** Static types for items */
	static const FPrimaryAssetType	AmmoItemType;
	static const FPrimaryAssetType	WeaponItemType;

	/** Returns the current AssetManager object */
	static UAssetManagerMain& Get();
};
