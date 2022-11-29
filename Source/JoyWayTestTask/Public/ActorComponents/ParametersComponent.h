// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Struct/Parameters/Parameters.h"
#include "ParametersComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType )
class JOYWAYTESTTASK_API UCharacterParametersComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	FCombatParameters CombatParameters;
	
public:	
	// Sets default values for this component's properties
	UCharacterParametersComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
