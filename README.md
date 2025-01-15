# cpp06
cpp의 다양한 캐스팅에 대해 배우는 과제입니다.

---
목차
1. 과제를 통해 알게 된 것  
2. 평가 피드백
---

1. 과제를 통해 알게 된 것

1-1) 다양한 종류의 캐스팅  
C언어에서 공부했던 형변환과 달리  c++에는 다양한 종류의 형변환들이 있었습니다.  
구체적인 내용은 아래와 같습니다.  

1-1-1) static_cast  
가장 기본적이고 일반적인 형 변환에 사용됩니다. 컴파일 시점에 형 검사를 수행합니다.  
~~~ c++
double d = 3.14;
int i = static_cast<int>(d);    // 3.14 -> 3
~~~

1-1-2) const_cast  
const 또는 volatile 지정자를 제거할 때 사용됩니다.  
const 객체를 수정해야 하는 레거시 코드를 다룰 때 사용  
~~~ c++
const int constant = 21;
int* modifiable = const_cast<int*>(&constant);
~~~

1-1-3) reinterpret_cast   
포인터나 정수 간의 위험한 형 변환에 사용됩니다. 비트 단위 재해석을 수행합니다.  
~~~ c++
int* p = new int(65);
char* ch = reinterpret_cast<char*>(p);
~~~


1-1-4) dynamic_cast  
다형성 클래스 간의 안전한 다운캐스팅을 위해 사용됩니다. 런타임에 타입 검사를 수행합니다.
~~~ c++
Base* base = new Derived();
Derived* derived = dynamic_cast<Derived*>(base);  // 실패시 nullptr 반환
~~~

1-2) 다운캐스팅과 업케스팅  

1-2-1) 업캐스팅  
자식 클래스의 포인터/참조를 부모 클래스의 포인터/참조로 변환하는 것입니다.  
항상 안전하며 암시적 변환이 가능하다는 특징이 있습니다.  
~~~ c++
class Animal { };
class Dog : public Animal { };

Dog* dog = new Dog();
Animal* animal = dog;  // 업캐스팅 - 암시적으로 수행됨
// 또는
Animal* animal = static_cast<Animal*>(dog);  // 명시적 업캐스팅
~~~

1-2-2) 다운캐스팅  
부모 클래스의 포인터/참조를 자식 클래스의 포인터/참조로 변환하는 것입니다.  
위험할 수 있으며 반드시 명시적으로 수행해야 합니다.  
~~~ c++
Animal* animal = new Dog();  // 실제로 Dog 객체를 가리킴
Dog* dog = dynamic_cast<Dog*>(animal);  // 다운캐스팅

Animal* animal2 = new Animal();  // Animal 객체
Dog* dog2 = dynamic_cast<Dog*>(animal2);  // 실패: nullptr 반환
~~~

2. 평가 피드백
<img width="967" alt="image" src="https://github.com/user-attachments/assets/65ca1fb2-eb9a-465f-ad10-e2a110144113" />


