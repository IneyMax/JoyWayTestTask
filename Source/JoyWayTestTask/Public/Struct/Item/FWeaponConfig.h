// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FWeaponConfig.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct JOYWAYTESTTASK_API FWeaponConfig
{
	GENERATED_BODY()

	FWeaponConfig()
		: ShotsDelay(1),
		ReloadTime(1),
		WeaponDamage(0),
		ShopCapacity(0)
	{
	}

	FWeaponConfig(float InShotsDelay, float InReloadTime, int32 InWeaponDamage, int32 InShopCapacity)
		: ShotsDelay(InShotsDelay),
		ReloadTime(InReloadTime),
		WeaponDamage(InWeaponDamage),
		ShopCapacity(InShopCapacity)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	float ShotsDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	float ReloadTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	int32 WeaponDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	int32 ShopCapacity;
};