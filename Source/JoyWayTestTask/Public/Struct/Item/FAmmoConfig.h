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
		: Speed(0),
		MaxFlightDistance(0),
		BulletDamage(0)
	{
	}

	FAmmoConfig(float InSpeed, float InMaxFlightDistance, int32 InBulletDamage)
		: Speed(InSpeed),
		MaxFlightDistance(InMaxFlightDistance),
		BulletDamage(InBulletDamage)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ammo)
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ammo)
	float MaxFlightDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ammo)
	int32 BulletDamage;
};