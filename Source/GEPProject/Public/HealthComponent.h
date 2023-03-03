// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FComponentDeadSignature, AController*, causer);

UCLASS()
class GEPPROJECT_API AHealthComponent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHealthComponent();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintAssignable, Category = "Components")
	FComponentDeadSignature onComponentDead;

protected:
	// Variables
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Health")
	float m_CurrentHealth;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Health")
	float m_MaxHealth;

	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Shield")
	float m_CurrentShield;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Shield")
	float m_MaxShield;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Shield")
	bool m_CanRegenShield;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Shield")
	float m_ShieldRecoverDelayTimer;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Shield")
	float m_ShieldRecoverRate;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Shield")
	float m_ShieldRecoverDelay;

	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void DamageTaken(AActor* damagedActor, float damage, const UDamageType* damageType, AController* instigator, AActor* causer);
	
	

};
