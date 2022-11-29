// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/AssetManagerMain.h"
#include "Engine/AssetManager.h"
#include "Item/Weapon/WeaponBase.h"
#include "ItemData/InventoryItemBase.h"
#include "InventoryItemWeapon.generated.h"

/**
 * 
 */
UCLASS()
class JOYWAYTESTTASK_API UInventoryItemWeapon : public UInventoryItemBase
{
	GENERATED_BODY()

public:
	/** Constructor */
	UInventoryItemWeapon()
	{
		ItemType = UAssetManagerMain::WeaponItemType;
	}
	
	/** Weapon actor to spawn */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Weapon)
	TSubclassOf<AWeaponBase> WeaponClass;

	/** Weapon actor to spawn */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Weapon)
	TArray<TSubclassOf<AAmmoBase>> AmmoClasses;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Weapon)
	FWeaponConfig WeaponStats;
};
