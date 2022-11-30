// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemData/InventoryItemBase.h"
#include "PickupBase.generated.h"

UCLASS()
class JOYWAYTESTTASK_API APickupBase : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InventoryItem)
	UInventoryItemBase* InventoryItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InventoryItem)
	int32 ItemCount;

public:	
	// Sets default values for this actor's properties
	APickupBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
