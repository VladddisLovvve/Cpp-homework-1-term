#include "Header2.hpp"


//int a();
// ошибка линковщика - неразрешенный внешний символ.
// Линковщик не может найти опредление внешнего символа.
// Для решение необходимо задать определение или ввести это определение в поле зрения линковщика

int b() { return 0; }
int b() { return 1; }
// Ошибка линковщика: обнаружен многократно определенный символ - один или более
// Линковщик обнаружил несколько определений одной и той же сущности в разных единицах трансляции
// Необходимо убрать лишние определения
//

main()
{
	//a();
	b();

	return 0;
}
