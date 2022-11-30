// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FItemSlot.generated.h"


/**
 * 
 */
USTRUCT(BlueprintType)
struct JOYWAYTESTTASK_API FItemSlot
{
	GENERATED_BODY()

	FItemSlot()
		: SlotNumber(-1)
	{}

	FItemSlot(const FPrimaryAssetType& InItemType, int32 InSlotNumber)
		: SlotType(InItemType)
		, SlotNumber(InSlotNumber)
	{}
	
	/** The type of items that can go in this slot */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Slot)
	FPrimaryAssetType SlotType;

	/** The number of this slot, 0 indexed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Slot)
	int32 SlotNumber;

	/** Equality operators */
	bool operator==(const FItemSlot& Other) const
	{
		return SlotType == Other.SlotType && SlotNumber == Other.SlotNumber;
	}
	
	bool operator!=(const FItemSlot& Other) const
	{
		return !(*this == Other);
	}

	/** Implemented so it can be used in Maps/Sets */
	friend inline uint32 GetTypeHash(const FItemSlot& Key)
	{
		uint32 Hash = 0;

		Hash = HashCombine(Hash, GetTypeHash(Key.SlotType));
		Hash = HashCombine(Hash, GetTypeHash(Key.SlotNumber));
		return Hash;
	}

	/** Returns true if slot is valid */
	bool IsValid() const
	{
		return SlotType.IsValid() && SlotNumber >= 0;
	}
};