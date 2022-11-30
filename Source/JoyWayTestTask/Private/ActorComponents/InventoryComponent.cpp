// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorComponents/InventoryComponent.h"

#include "Core/GameInstanceMain.h"
#include "Core/SaveGame/SaveGameMain.h"
#include "JoyWayTestTask/JoyWayTestTask.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}


bool UInventoryComponent::SaveInventory()
{
	UWorld* World = GetWorld();
	UGameInstanceMain* GameInstance = World ? World->GetGameInstance<UGameInstanceMain>() : nullptr;

	if (!GameInstance)
	{
		return false;
	}

	/*
	USaveGameMain* CurrentSaveGame = GameInstance->GetCurrentSaveGame();
	if (CurrentSaveGame)
	{
		// Reset cached data in save game before writing to it
		CurrentSaveGame->InventoryData.Reset();
		CurrentSaveGame->SlottedItems.Reset();

		for (const TPair<URPGItem*, FRPGItemData>& ItemPair : InventoryData)
		{
			FPrimaryAssetId AssetId;

			if (ItemPair.Key)
			{
				AssetId = ItemPair.Key->GetPrimaryAssetId();
				CurrentSaveGame->InventoryData.Add(AssetId, ItemPair.Value);
			}
		}

		for (const TPair<FRPGItemSlot, URPGItem*>& SlotPair : SlottedItems)
		{
			FPrimaryAssetId AssetId;

			if (SlotPair.Value)
			{
				AssetId = SlotPair.Value->GetPrimaryAssetId();
			}
			CurrentSaveGame->SlottedItems.Add(SlotPair.Key, AssetId);
		}

		// Now that cache is updated, write to disk
		GameInstance->WriteSaveGame();
		return true;
	}
	*/
	return false;
}

bool UInventoryComponent::LoadInventory()
{
	return false;
}

bool UInventoryComponent::GetInventoryItemData(UInventoryItemBase* Item, FInventoryItemData& ItemData) const
{
	const FInventoryItemData* FoundItem = InventoryData.Find(Item);

	if (FoundItem)
	{
		ItemData = *FoundItem;
		return true;
	}
	ItemData = FInventoryItemData(0);
	return false;
}

bool UInventoryComponent::AddInventoryItem(UInventoryItemBase* NewItem, int32 ItemCount)
{
	if (!NewItem)
	{
		UE_LOG(LogJWProject, Warning, TEXT("AddInventoryItem: Failed trying to add null item!"));
		return false;
	}

	if (ItemCount <= 0)
	{
		UE_LOG(LogJWProject, Warning, TEXT("AddInventoryItem: Failed trying to add item %s with negative count!"), *NewItem->GetName());
		return false;
	}

	// Find current item data, which may be empty
	FInventoryItemData OldData;
	GetInventoryItemData(NewItem, OldData);

	// Find modified data
	FInventoryItemData NewData = OldData;
	NewData.UpdateItemData(FInventoryItemData(ItemCount), NewItem->MaxCount);

	/*
	FString NewDataString = FString::FromInt(ItemCount);
	UE_LOG(LogJWProject, Warning, TEXT("Text, %s"), *NewDataString);
	*/

	if (OldData != NewData)
	{
		// If data changed, need to update storage and call callback
		InventoryData.Add(NewItem, NewData);
		NotifyInventoryItemChanged(true, NewItem);
		SaveInventory();
		return true;
	}
	
	return false;
}


bool UInventoryComponent::RemoveInventoryItem(int32& NewCount, UInventoryItemBase* RemovedItem, int32 RemoveCount)
{
	if (!RemovedItem)
	{
		UE_LOG(LogJWProject, Warning, TEXT("RemoveInventoryItem: Failed trying to remove null item!"));
		return false;
	}

	// Find current item data, which may be empty
	FInventoryItemData NewData;
	GetInventoryItemData(RemovedItem, NewData);

	if (!NewData.IsValid())
	{
		// Wasn't found
		return false;
	}
	
	// If RemoveCount <= 0, delete all
	if (RemoveCount <= 0)
	{
		NewData.ItemCount = 0;
		NewCount = 0;
	}
	else
	{
		NewData.ItemCount -= RemoveCount;
		NewCount = NewData.ItemCount;
	}
	
	if (NewData.ItemCount > 0)
	{
		// Update data with new count
		InventoryData.Add(RemovedItem, NewData);
	}
	else
	{
		// Remove item entirely, make sure it is unslotted
		InventoryData.Remove(RemovedItem);
	}

	// If we got this far, there is a change so notify and save
	NotifyInventoryItemChanged(false, RemovedItem);
	SaveInventory();
	return true;
}

void UInventoryComponent::GetInventoryItemsByType(TArray<UInventoryItemBase*>& Items, FPrimaryAssetType ItemType)
{
	for (const TPair<UInventoryItemBase*, FInventoryItemData>& Pair : InventoryData)
	{
		if (Pair.Key)
		{
			FPrimaryAssetId AssetId = Pair.Key->GetPrimaryAssetId();

			// Filters based on item type
			if (AssetId.PrimaryAssetType == ItemType || !ItemType.IsValid())
			{
				Items.Add(Pair.Key);
			}
		}	
	}
}

int32 UInventoryComponent::GetInventoryItemCount(UInventoryItemBase* Item) const
{
	const FInventoryItemData* FoundItem = InventoryData.Find(Item);

	if (FoundItem)
	{
		return FoundItem->ItemCount;
	}
	return 0;
}


void UInventoryComponent::NotifyInventoryItemChanged(bool bAdded, UInventoryItemBase* Item)
{
	// Notify native before blueprint
	OnInventoryItemChangedNative.Broadcast(bAdded, Item);
	OnInventoryItemChanged.Broadcast(bAdded, Item);

	// Call BP update event
	InventoryItemChanged(bAdded, Item);
}

