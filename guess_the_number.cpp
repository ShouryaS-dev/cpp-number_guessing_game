#include <iostream>
#include <random>

int num_generator()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<>dist(1,100);

    int num {dist(gen)};
    return num;
}

int main()
{
    int num {num_generator()};
    int counter{0};
    int guess{};
    
    std::cout<<"Welcome to the number guessing game!\nThe range is 1 to 100 (both included)\n";
    std::cout<<"Let's see how many tries it takes you to get the right number !\n";

    while(true)
    {
        std::cin>>guess;
        if (guess>=0 && guess<=100)
        {
            while (guess != num)
            {
                while(guess<0 || guess>100)
                {
                    std::cout<<"Kindly enter a number between 0 and 100\n";
                    std::cin>>guess;
                }

                if (guess<num)
                {
                    std::cout<<"Try higher\n";
                    counter+=1;
                }
                else
                {
                    std::cout<<"Try lower\n";
                    counter+=1;
                }
                std::cin>>guess;


            }
            counter+=1;
            std::cout<<"Thats correct!\nYou got "<<num<<" in "<<counter<<" attempts";
            return 0;
        }

        std::cout<<"Kindly enter a number between 0 and 100\n";
    }

}
