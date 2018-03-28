// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTGITSOURCEENN_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(meta = (BindWidget))
	class UButton * host;
	UPROPERTY(meta = (BindWidget))
	class UButton* Join;

	UFUNCTION()
		void dohost();
protected:
	virtual bool Initialize() override;


	class IMyUMGInterface* Interface;

public:

	void SetInterface(IMyUMGInterface* inter);
	
};
