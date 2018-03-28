// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyUMGInterface.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */


UCLASS()
class TESTGITSOURCEENN_API UMyGameInstance : public UGameInstance,public IMyUMGInterface
{
	GENERATED_BODY()
	
protected:

private:

	TSubclassOf<class UUserWidget> mainmenuclass;

public:

	UMyGameInstance(const FObjectInitializer & ObjectInitializer);

	virtual void Init();
	UFUNCTION()
	void host();

	UFUNCTION(BlueprintCallable)
	void loadmainmenu();
	UFUNCTION()
	void join(const FString& url);

};
