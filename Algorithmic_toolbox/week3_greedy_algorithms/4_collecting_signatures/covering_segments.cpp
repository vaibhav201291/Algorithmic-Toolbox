#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;
using namespace std;

struct Segment
{
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments)
{
  vector<int> points;
  //write your code here

  // vector<int> startPoints;
  // vector<int> endPoints;

  int startP = segments[0].start;
  int endP = segments[0].end;
  int currentIndex = 0;

  for (size_t i = 0; i < segments.size(); i++)
  {
    if (segments[i].start < startP)
    {
      startP = segments[i].start;
      currentIndex = i;
    }
    if (segments[i].end >= endP)
    {
      endP = segments[i].end;
    }
  }
  points.push_back(segments[currentIndex].end);
  int gap = 1;
  // cout << "end : " << endP << endl;

  while ((startP <= endP) && (gap <= endP))
  {
    for (int i = 0; i < segments.size(); i++)
    {
      // cout<<i<<endl;
      if (segments[i].start == (segments[currentIndex].end + gap))
      {
        for (int j = 0; j < segments.size(); j++)
        {
          if (segments[i].start <= segments[j].start && segments[i].end >= segments[j].end)
          {
            currentIndex = j;
            startP = segments[currentIndex].end;
            // points.push_back(segments[currentIndex].end);
          }
          else
          {
            currentIndex = i;
            startP = segments[currentIndex].end;
          }
        }

        points.push_back(segments[currentIndex].end);
      }
    }
    gap++;
    // cout<<"gap "<<gap<<endl;
  }

  // for (size_t i = 0; i < segments.size(); ++i)
  // {
  //   points.push_back(segments[i].start);
  //   points.push_back(segments[i].end);
  // }
  return points;
}

int main()
{
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i)
  {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i)
  {
    std::cout << points[i] << " ";
  }
  cout << endl;
}
