// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveGameMain.generated.h"


/**
 * 
 */
UCLASS()
class JOYWAYTESTTASK_API USaveGameMain : public USaveGame
{
	GENERATED_BODY()
	
};

/** Delegate called when the entire inventory has been loaded */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSaveGameLoaded, USaveGameMain*, SaveGame);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnSaveGameLoadedNative, USaveGameMain*);