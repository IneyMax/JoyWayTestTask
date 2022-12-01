// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Struct/Parameters/Parameters.h"
#include "CombatParametersComponent.generated.h"


/** Delegate called when an Health Changed */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChanged, int32, CurrenHealth, int32, MaxHealth);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnHealthChangedNative, int32, int32);

/** Delegate called when an Take Damage */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTakeDamage, int32, DamageAmount, AActor*, DamageSource);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnTakeDamageNative, int32, AActor*);


UCLASS( ClassGroup=(CombatParameters), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType )
class JOYWAYTESTTASK_API UCombatParametersComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCombatParametersComponent ();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CombatParameters)
	FCombatParameters CombatParameters;
	
protected:
	UFUNCTION(BlueprintCallable, Category = CharacterStats)
	void GetHealthStats (int32& CurrenHP, int32& MaxHP) const;

	UFUNCTION(BlueprintCallable, Category = CharacterStats)
	void TakeDamage(int32 DamageSize, AActor* DamageSource);

	UFUNCTION(BlueprintCallable, Category = CharacterStats)
	void HealthRecover(int32 RecoverableHealth);

	/** Delegate called when an Health Changed */
	UPROPERTY(BlueprintAssignable, Category = CharacterStats)
	FOnHealthChanged OnHealthChanged;

	/** Native version above, called before BP delegate */
	FOnHealthChangedNative OnHealthChangedNative;

	UPROPERTY(BlueprintAssignable, Category = CharacterStats)
	FOnTakeDamage OnTakeDamage;

	/** Native version above, called before BP delegate */
	FOnTakeDamageNative OnTakeDamageNative;
	
	/** Called after the inventory was changed and we notified all delegates */
	UFUNCTION(BlueprintImplementableEvent, Category = CharacterStats)
	void CallHealthChanged(int32 CurrentHP, int32 MaxHP);

	/** Called after the inventory was changed and we notified all delegates */
	UFUNCTION(BlueprintImplementableEvent, Category = CharacterStats)
	void CallTakeDamage(int32 DamageSize, AActor* DamageSource);

	void NotifyHealthChanged(int32 CurrentHP, int32 MaxHP);
	void NotifyTakeDamage(int32 DamageSize, AActor* DamageSource);
};

