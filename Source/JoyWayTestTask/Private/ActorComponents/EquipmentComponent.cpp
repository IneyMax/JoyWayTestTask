// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorComponents/EquipmentComponent.h"

// Sets default values for this component's properties
UEquipmentComponent::UEquipmentComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();

	for (auto Slot : SlotsConfig)
	{
		SlottedItems.Add(Slot, nullptr);
	}

	NotifyEquipmentLoaded();
}


bool UEquipmentComponent::SetSlottedItem(FItemSlot ItemSlot, UInventoryItemBase* Item)
{
	if (ItemSlot.IsValid())
	{
		SlottedItems.Add(ItemSlot, Item);
		NotifySlottedItemChanged(ItemSlot, Item);
		if (IsValid(Item))
		{
			return true;
		}
	}
	return false;
}

UInventoryItemBase* UEquipmentComponent::GetSlottedItem(FItemSlot ItemSlot) const
{
	UInventoryItemBase* const* FoundItem = SlottedItems.Find(ItemSlot);

	if (FoundItem)
	{
		return *FoundItem;
	}
	return nullptr;
}

void UEquipmentComponent::GetSlottedItemsByType(TArray<UInventoryItemBase*>& Items, FPrimaryAssetType ItemType)
{
	for (TPair<FItemSlot, UInventoryItemBase*>& Pair : SlottedItems)
	{
		if (Pair.Key.SlotType == ItemType || !ItemType.IsValid())
		{
			Items.Add(Pair.Value);
		}
	}
}

void UEquipmentComponent::GetAllSlots(TArray<FItemSlot>& Slots) const
{
	SlottedItems.GetKeys(Slots);
}

void UEquipmentComponent::NotifySlottedItemChanged(FItemSlot ItemSlot, UInventoryItemBase* Item)
{
	// Notify native before blueprint
	OnSlottedItemChangedNative.Broadcast(ItemSlot, Item);
	OnSlottedItemChanged.Broadcast(ItemSlot, Item);

	// Call BP update event
	SlottedItemChanged(ItemSlot, Item);
}

void UEquipmentComponent::NotifyEquipmentLoaded()
{
	OnEquipmentLoaded.Broadcast();
	OnEquipmentLoadedNative.Broadcast();
}

