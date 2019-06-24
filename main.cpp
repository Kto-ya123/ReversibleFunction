/*#include <iostream>

using namespace std;

struct Image {
  double quality;
  double freshness;
  double rating;
};

struct Params {
  double a;
  double b;
  double c;
};*/
#include<vector>
//#include<pair>
using namespace std;

struct Function{
    void AddPart(const char& sign, double amount){
        total.push_back(pair<char, double>{sign, amount});
    }
    double Apply(double amount)const {
        for(const auto& operation : total){
            switch(operation.first){
                case '+':
                    amount += operation.second;
                    break;
                case '-':
                    amount -= operation.second;
                    break;
                case '*':
                    amount *= operation.second;
                    break;
                case '/':
                    amount /= operation.second;
                    break;
            }
        }
        return amount;
    }
    void Invert(){
        for(auto& operation : total){
            switch(operation.first){
                case '+':
                    operation.first = '-';
                    break;
                case '-':
                    operation.first = '+';
                    break;
                case '*':
                    operation.first = '/';
                    break;
                case '/':
                    operation.first = '*';
                    break;
            }
        }
        vector<pair<char, double>> reverseTotal;
        for(int i(total.size() - 1); i >= 0; i--){
            reverseTotal.push_back(total[i]);
        }
        total = reverseTotal;
    }
    vector<pair<char, double>> total;

};

/*Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  Function function;
  function.AddPart('*', params.a);
  function.AddPart('-', image.freshness * params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}

int main() {
  Image image = {10, 2, 6};
  Params params = {4, 2, 6};
  cout << ComputeImageWeight(params, image) << endl;
  cout << ComputeQualityByWeight(params, image, 52) << endl;
  return 0;
}*/
