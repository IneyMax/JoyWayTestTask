// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemData/InventoryItemBase.h"
#include "Struct/Item/FItemSlot.h"
#include "EquipmentComponent.generated.h"

/** Delegate called when the contents of an inventory slot change */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSlottedItemChanged, FItemSlot, ItemSlot, UInventoryItemBase*, Item);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnSlottedItemChangedNative, FItemSlot, UInventoryItemBase*);

/** Delegate called when the entire Equipment has been loaded */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEquipmentLoaded);
DECLARE_MULTICAST_DELEGATE(FOnEquipmentLoadedNative);

UCLASS( ClassGroup=(Equipment), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType )
class JOYWAYTESTTASK_API UEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEquipmentComponent();

protected:
	/** Map of slot, from type/num to item */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment)
	TArray<FItemSlot> SlotsConfig;
	
	/** Map of slot, from type/num to item */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Equipment)
	TMap<FItemSlot, UInventoryItemBase*> SlottedItems;

	/** Map of slot, from type/num to Actor */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Equipment)
	TMap<FItemSlot, AActor*> ActorToSlots;

public:
	/** Delegate called when an inventory slot has changed */
	UPROPERTY(BlueprintAssignable, Category = Equipment)
	FOnSlottedItemChanged OnSlottedItemChanged;

	/** Native version above, called before BP delegate */
	FOnSlottedItemChangedNative OnSlottedItemChangedNative;
	
	/** Delegate called when the Equipment has been loaded/reloaded */
	UPROPERTY(BlueprintAssignable, Category = Inventory)
	FOnEquipmentLoaded OnEquipmentLoaded;

	/** Native version above, called before BP delegate */
	FOnEquipmentLoadedNative OnEquipmentLoadedNative;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	/** Called after an item was equipped and we notified all delegates */
	UFUNCTION(BlueprintImplementableEvent, Category = Equipment)
	void SlottedItemChanged(FItemSlot ItemSlot, UInventoryItemBase* Item);
	
	/** Sets slot to item, will remove from other slots if necessary. If passing null this will empty the slot */
	UFUNCTION(BlueprintCallable, Category = Equipment)
	bool SetSlottedItem(FItemSlot ItemSlot, UInventoryItemBase* Item);

	/** Returns item in slot, or null if empty */
	UFUNCTION(BlueprintPure, Category = Equipment)
	UInventoryItemBase* GetSlottedItem(FItemSlot ItemSlot) const;

	/** Returns all slotted items of a given type. If none is passed as type it will return all */
	UFUNCTION(BlueprintPure, Category = Equipment)
	void GetSlottedItemsByType(TArray<UInventoryItemBase*>& Items, FPrimaryAssetType ItemType);

	/** Returns All Slots for Item */
	UFUNCTION(BlueprintCallable, Category = Equipment)
	void GetAllSlots(TArray<FItemSlot>& Slots) const;
	
	void NotifySlottedItemChanged(FItemSlot ItemSlot, UInventoryItemBase* Item);
	void NotifyEquipmentLoaded();
};
