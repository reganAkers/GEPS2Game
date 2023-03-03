// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Test.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FComponentDeadSignature, AController*, causer);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GEPPROJECT_API UTest : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	UTest();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable, Category = "Components")
	FComponentDeadSignature onComponentDead;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

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
	

	UFUNCTION()
	void DamageTaken(AActor* damagedActor, float damage, const UDamageType* damageType, AController* instigator, AActor* causer);

		
};
