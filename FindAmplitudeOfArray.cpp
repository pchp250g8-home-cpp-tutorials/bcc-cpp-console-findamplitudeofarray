#include <iostream>
#include <valarray>
#include <stdlib.h>
#include <math.h>
#include <tchar.h>

int _tmain(int argc, _TCHAR* argv[])
{
   int nElems;
   std::cout << "Input a count of elements in array\r\n";
   std::cin >> nElems;
   if (nElems == 0)
   {
		std::cout << "Empty arrays not allowed\r\n";
    	std::cin.ignore();
    	std::cin.get();
    	return 1;
   }
   std::valarray<int> iNumbers(nElems);
   srand(time(nullptr));
   std::cout << "Generating array by filling " << nElems << " elements\r\n";
   for (int i = 0; i < nElems; i++)
   {
   		iNumbers[i] = 1 + rand() % 100;
    	std::cout << iNumbers[i] << " ";
   }
   int iMax = iNumbers[0];
   int nMaxIndex = 0;
   int iMin = iNumbers[0];
   int nMinIndex = 0;
   for (int i = 1; i < nElems; i++)
   {
        if (iNumbers[i] > iMax)
        {
        	iMax = iNumbers[i];
        	nMaxIndex = i;
        }
        if (iNumbers[i] < iMin)
        {
            iMin = iNumbers[i];
            nMinIndex = i;
        }
   }
   std::cout << "\r\nFound maximum element: " << iMax << " with index "
   			 << nMaxIndex << "\r\n";
   std::cout << "Found minimum element: " << iMin << " with index "
   			 << nMinIndex << "\r\n";
   std::cout << "Found amplitude:" << iMax - iMin << "\r\n";
   std::cin.ignore();
   std::cin.get();
}
