#include <stack>
#include <iostream>

void tower_of_hanoi(int n)
{
   int idle = 0;
   std::stack<int> pegs[3];

   // Number disc 1 through n, n is largest
   for (int i = 0; i < n; i++)
   {
      pegs[0].push(n - i);
   }

   std::cout << "ready!" << std::endl;
   while (pegs[2].size() < n)
   {
      idle = (idle + 1) % 3;
      int from, to;
      switch (idle)
      {
      case 0:
         from = 1;
         to = 2;
         break;
      case 1:
         from = 0;
         to = 2;
         break;
      case 2:
         from = 0;
         to = 1;
         break;
      }
      // Must move smaller disc to larger disc
      if (pegs[from].empty() ||
         (!pegs[to].empty() && pegs[from].top() > pegs[to].top()))
      {
         std::swap(from, to);
      }

      int disc = pegs[from].top();
      std::cout << "Move disc " << disc << " from " << from << " to " << to << std::endl;
      pegs[from].pop();
      pegs[to].push(disc);
   }
}

int main(int argc, char *argv[])
{
   time_t start, end;

   time(&start);
   tower_of_hanoi(99999);
   time(&end);

   double time_taken = double(end - start);
   std::cout << "Time taken by program is : " << std::fixed << time_taken;
   std::cout << " sec " << std::endl;
}
