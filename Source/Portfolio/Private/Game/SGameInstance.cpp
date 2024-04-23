// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/SGameInstance.h"
#include "Kismet/KismetSystemLibrary.h"
#include "SUnrealObjectClass.h"

USGameInstance::USGameInstance()
{
	UE_LOG(LogTemp, Log, TEXT("경고나 에러가 아닙니다."));

	Name = TEXT("USGameInstance에서 Name변수값을 설정했습니다");
}

void USGameInstance::Init()
{
	Super::Init(); // 엔진 업데이트 루틴을 지키기 위해서, 언리얼 엔지니어가 작성한 코드가 먼저 실행되게끔 하기 위함.
	
	UE_LOG(LogTemp, Log, TEXT("게임이 시작되었습니다."));


	/*
	UKismetSystemLibrary::PrintString(this, TEXT("프린트 스트링 : 게임이 실행될 때 출력"));

	UClass* RuntimeClassInfo = GetClass();
	UClass* CompleteClassInfo = StaticClass();

	UE_LOG(LogTemp, Log, TEXT("Class Name : %s"),*RuntimeClassInfo->GetName());

	Name = TEXT("USGameInstance 변경된 값");

	//GetDefaultObject을 통해 USGameInstance형변환을 시켜서 Name값을 접근해서 가져온다.
	//형변환을 통해 요청한 것은 Instance에서 초기화된 내용을 가져온다
	//아래는 Init()에서 초기화한 내용이 반영된다.
	UE_LOG(LogTemp, Log, TEXT("USGameInstance Name : %s"), *(GetClass()->GetDefaultObject<USGameInstance>()->Name));
	
	UE_LOG(LogTemp, Log, TEXT("USGameInstance Name : %s"), *(Name));
	
	*/

	//언리얼은 new키워드를 사용하지 않고 NewObject<>()API를 사용한다.
	//아래줄의 코드는 USUnrealObjectClass를 접근하기 위한 내용
	USUnrealObjectClass* USobject1 = NewObject<USUnrealObjectClass>();

	//정의한 Getter()
	
	UE_LOG(LogTemp, Log, TEXT("USobject Name : %s"), *USobject1->GetName());

	//USUnrealObjectClass에서 name이라는 프로퍼티가 있으면 가져온다.
	FProperty* NameProperty = USUnrealObjectClass::StaticClass()->FindPropertyByName(TEXT("Name"));

	FString CompiletimeUSObjectName;

	if (nullptr != NameProperty) {
		NameProperty->GetValue_InContainer(USobject1, &CompiletimeUSObjectName);
		UE_LOG(LogTemp, Log, TEXT("CompiletimeUSObjectName Name : %s"), *CompiletimeUSObjectName);
	}

	USobject1->HelloUnreal();
	UFunction* HelloUnrealFunction = USobject1->GetClass()->FindFunctionByName(TEXT("HelloUnreal"));
	if (nullptr != HelloUnrealFunction) {
		USobject1->ProcessEvent(HelloUnrealFunction, nullptr);
	}
}

void USGameInstance::Shutdown()
{
	Super::Shutdown(); // 엔진 업데이트 루틴을 지키기 위해서, 언리얼 엔지니어가 작성한 코드가 먼저 실행되게끔 하기 위함.

	UE_LOG(LogTemp, Log, TEXT("게임이 꺼졌습니다."));

	
}
