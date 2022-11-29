// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FAmmoConfig.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct JOYWAYTESTTASK_API FAmmoConfig
{
	GENERATED_BODY()

	FAmmoConfig()
	: Speed(100),
	BulletDamage(0)
	{
	}

	FAmmoConfig(float InSpeed, int32 InBulletDamage)
	: Speed(InSpeed),
	BulletDamage(InBulletDamage)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ammo)
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ammo)
	int32 BulletDamage;
};