// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/AssetManagerMain.h"
#include "JoyWayTestTask/JoyWayTestTask.h"

const FPrimaryAssetType	UAssetManagerMain::AmmoItemType = TEXT("Ammo");
const FPrimaryAssetType	UAssetManagerMain::WeaponItemType = TEXT("Weapon");

UAssetManagerMain& UAssetManagerMain::Get()
{
	UAssetManagerMain* This = Cast<UAssetManagerMain>(GEngine->AssetManager);

	if (This)
	{
		return *This;
	}
	else
	{
		UE_LOG(LogJWProject, Fatal, TEXT("Invalid AssetManager in DefaultEngine.ini, must be RPGAssetManager!"));
		return *NewObject<UAssetManagerMain>(); // never calls this
	}
}
