// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/SGameInstance.h"
#include "Kismet/KismetSystemLibrary.h"
#include "SUnrealObjectClass.h"
#include "Example/SFlyable.h"
#include "Example/Spigeon.h"
#include "JsonObjectConverter.h"
#include "UObject/SavePackage.h"

USGameInstance::USGameInstance()
{
	UE_LOG(LogTemp, Log, TEXT("경고나 에러가 아닙니다."));

	Name = TEXT("USGameInstance에서 Name변수값을 설정했습니다");
}

void USGameInstance::Init()
{
	Super::Init(); // 엔진 업데이트 루틴을 지키기 위해서, 언리얼 엔지니어가 작성한 코드가 먼저 실행되게끔 하기 위함.
	

	//UTF-8로 저장해야 한글이 나온다
	UE_LOG(LogTemp, Log, TEXT("헬로우 언리얼!"));
	//언리얼 표ㅛ준 문자 자료형이 TCHAR
	TCHAR ArrayOfChar[] = TEXT("HELLO UNREAL");
	//문자열을 좀더 자유롭게 조작하고 싶으면 FString을 사용해야 한다.
	//TCHAR배열을 Wrapping한 헬퍼 클래스가 FString
	FString String0 = ArrayOfChar;
	FString String1 = FString(TEXT("HELLO UNREAL"));
	
	//FString은 *을 붙혀줘야 TCHAR배열에 반환이 된다
	UE_LOG(LogTemp, Log, TEXT("Strings1: %s"), *String1);

	const TCHAR* PtrToTChar = *String1;
	TCHAR* RawPtrToTChar = String1.GetCharArray().GetData();
	//ESearchCase::IgnoreCase : 대소문자를 무시한다
	if (String1.Contains(TEXT("unreal"), ESearchCase::IgnoreCase) == true)
	{
		int32 Index = String1.Find(TEXT("unreal"), ESearchCase::IgnoreCase);
		FString FoundedString = String1.Mid(Index);
		// "unreal" 문자열이 시작되는 곳에서부터 마지막까지 자름.
		UE_LOG(LogTemp, Log, TEXT("Founded string: %s"), *FoundedString);
	}

	int32 IntValue = 7;
	float FloatValue = 3.1415f;

	//문자열과 숫자를 합치고 싶을 때 사용
	FString StringWithNumbers = FString::Printf(TEXT("int32 : %d and float : %f"), IntValue, FloatValue);
	UE_LOG(LogTemp, Log, TEXT("String With Numbers : %s"), *StringWithNumbers);

	//Int형을 FString으로 변경해줌
	FString IntString = FString::FromInt(IntValue);
	UE_LOG(LogTemp, Log, TEXT("IntString: %s"), *IntString);

	// float 자료형의 표준은 상당히 복잡함. 이를 정돈해서 문자열로 바꿔줌.
	FString FloatString = FString::SanitizeFloat(FloatValue);
	UE_LOG(LogTemp, Log, TEXT("FloatString: %s"), *FloatString);

	//Atoi는 메모리 버퍼 공격에 취약하기때문에 권장되지 않는 함수이다
	int32 IntValueFromString = FCString::Atoi(*IntString);
	// C 문자열 라이브러리 함수(atoi(), strcpy(), ...)를 제공하는 클래스 FCString.
	UE_LOG(LogTemp, Log, TEXT("IntValueFromString: %d"), IntValueFromString);

}

void USGameInstance::Shutdown()
{
	Super::Shutdown(); // 엔진 업데이트 루틴을 지키기 위해서, 언리얼 엔지니어가 작성한 코드가 먼저 실행되게끔 하기 위함.

	UE_LOG(LogTemp, Log, TEXT("게임이 꺼졌습니다."));

	
}
