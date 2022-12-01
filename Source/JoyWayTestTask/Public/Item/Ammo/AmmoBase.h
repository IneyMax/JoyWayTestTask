// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Struct/Item/FAmmoConfig.h"
#include "AmmoBase.generated.h"

UCLASS()
class JOYWAYTESTTASK_API AAmmoBase : public AActor
{
	GENERATED_BODY()

public:	
	AAmmoBase();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Ammo)
	FAmmoConfig AmmoConfig;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Ammo)
	float CurrentFlightDistance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = Weapon)
	void Init (FAmmoConfig NewConfig);
};
