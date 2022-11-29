// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item/Ammo/AmmoBase.h"
#include "Struct/Item/FWeaponConfig.h"
#include "WeaponBase.generated.h"

UCLASS()
class JOYWAYTESTTASK_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Weapon)
	FWeaponConfig WeaponConfig;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Weapon)
	TSubclassOf<AAmmoBase> AmmoClass;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
