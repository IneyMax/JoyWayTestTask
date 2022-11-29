// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemData/InventoryItemBase.h"



bool UInventoryItemBase::IsConsumable() const
{
	if (MaxCount <= 0)
	{
		return true;
	}
	return false;
}

FString UInventoryItemBase::GetIdentifierString() const
{
	return GetPrimaryAssetId().ToString();
}

FPrimaryAssetType UInventoryItemBase::GetItemType() const
{
	return ItemType;
}

FPrimaryAssetId UInventoryItemBase::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(ItemType, GetFName());
}

