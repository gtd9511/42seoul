#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main(void)
{
    {
        std::cout << std::endl << std::endl;
        std::cout << "AMateria  test\n";
        std::cout << "copy operator test\n";

        AMateria *m1 = new Cure();
        AMateria *m2 = new Ice();
        std::cout << m1->getType() << std::endl;
        std::cout << m2->getType() << std::endl;

        *m2 = *m1;
        std::cout << m1->getType() << std::endl;
        std::cout << m2->getType() << std::endl;

        std::cout << "\nAMateria clone test (correct output : cure)\n";
        AMateria *c1 = m1->clone();
        std:: cout << c1->getType();
        std::cout << std::endl << std::endl;
        delete m1;
        delete m2;
        delete c1;
    }
    {
        std::cout << std::endl << std::endl;
        std::cout << "Materia Inherit test (has to call ~AMateria()\n";
        Cure *c =  new Cure();
        //~AMateria도  호출되어야.
        delete c;
    }
    {
        std::cout << std::endl << std::endl;
        std::cout << "test ICharacter (use function ,equip function) \n";
        //src에서 만들지 않고 직접 동적할당해서 장착해보았다.
        //AMateria 종류는 직접 해제하는 법 없이 캐릭터 또는 바닥이 소멸시 함께 해제한다.

        ICharacter *ch = new Character("character 1");
        AMateria *am1 = new Cure();//src->createMateria()와 같다.
        ch->equip(am1);
        AMateria *am2 = new Cure();
        ch->equip(am2);
        AMateria *am3 = new Cure();
        ch->equip(am3);
        AMateria *am4 = new Cure();
        ch->equip(am4);
        Character *ch2 = new Character("character 2");
        std::cout << am1 << " " << am2 << " " << am3 << " " << am4 << std::endl;
       

        ch->use(0, *ch2);
        ch->use(1, *ch2);
        ch->use(2, *ch2);
        ch->use(3, *ch2);

        ch->use(4, *ch2);
       //ICharacter, cure 둘다 삭제되어야.
        delete ch;
 

    }
    {
        std::cout << std::endl << std::endl;
        std::cout << "\ntest - Character copy operator(ch2가 잘 ch1의 Materia를 복사해서 사용하는가)\n ";
        //복사대입연산자
        Character ch1("T1");
        Character ch2("T2");
        AMateria *am1 = new Cure();//src->createMateria()와 같다.
        AMateria *am2 = new Cure();

        ch1.equip(am1);
        ch1.equip(am2);

        ch1.use(0, ch2);
        ch1.use(1, ch2);
        ch2 = ch1;
        ch2.use(0,ch1);
        ch2.use(1,ch1);
    }
    {
        std::cout << std::endl << std::endl;
        std::cout << "test floor(correct output : Cure, Cure) \n";
        Floor floor = Floor();
        floor.dropItem(new Cure());
        floor.dropItem(new Ice());
        floor.checkItem();
    }
    {
        std::cout << std::endl << std::endl;
        std::cout << "test MateriaSource\n";
        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Cure());
        src->learnMateria(new Ice());
        AMateria *m1 = src->createMateria("cure");
        AMateria *m2 = src->createMateria("ice");
        std::cout << m1->getType() << std::endl;
        std::cout << m2->getType() << std::endl; 
    }
    {
        std::cout << std::endl << std::endl;
        std::cout << "test Subject(see Subject)\n";
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
    }
    {
         std::cout << std::endl << std::endl;
        std::cout << "test unequip\n";
         IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        me->unequip(1);
        me->unequip(0);
        me->unequip(2);


    }
    return 0;
}
