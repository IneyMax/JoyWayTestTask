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
	: Health (100)
	{
	}

	FCombatParameters(int32 InHealth)
		: Health(InHealth)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterParameters)
	int32 Health;
};