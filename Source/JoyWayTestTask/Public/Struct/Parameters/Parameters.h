// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Parameters.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct JOYWAYTESTTASK_API FCombatParameters
{
	GENERATED_BODY()

	FCombatParameters()
		: CurrentHealth(100),
		MaxHealth(100)
	{
	}

	FCombatParameters(int32 InHealth, int32 InMaxHealth)
		: CurrentHealth(InHealth),
		MaxHealth(InMaxHealth)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterParameters)
	int32 CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterParameters)
	int32 MaxHealth;
};