#include <iostream>

#include "Algorithms.h"
#include "DataStructures.h"
#include "Maths.h"
#include "Matrix.h"
#include "Vector.h"

#include <math.h>
#include <algorithm>

#include <memory>

int main()
{
    std::shared_ptr<Stack<int>> ptr = nullptr;

    {
        std::shared_ptr<Stack<int>> temp = std::make_shared<Stack<int>>();
       
        {
            ptr = temp;
        }

        temp->Push(1);
        temp->Push(3);
        temp->Push(7);
    }
    //vector
    //add
    //subtract

    std::cout << ptr->Peek() << '\n';

    std::cout << "end of app\n";
}


