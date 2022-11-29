// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/AssetManagerMain.h"
#include "Item/Ammo/AmmoBase.h"
#include "ItemData/InventoryItemBase.h"
#include "InventoryItemAmmo.generated.h"

/**
 * 
 */
UCLASS()
class JOYWAYTESTTASK_API UInventoryItemAmmo : public UInventoryItemBase
{
	GENERATED_BODY()

public:
	/** Constructor */
	UInventoryItemAmmo()
	{
		ItemType = UAssetManagerMain::AmmoItemType;
	}
	
	/** Weapon actor to spawn */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Ammo)
	TSubclassOf<AAmmoBase> AmmoClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Ammo)
	FAmmoConfig AmmoStats;
};
