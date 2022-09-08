
using namespace std;

struct Airport{
  string name;
  string location;
  string code;
  int index;
  Airport(string n, string l, string c, int i) { name = n; location = l; code = c; index = i; }
};
//In this class we have a map of airports, that we'll correspond with our graph. The key for each Airport will be the key used for the vertex in the Graph.

class AirportData{
  public: 
    map<int, Airport> airports;
    void fill(){
      //adding and creating Airport objects to the map.
      airports.emplace(0, Airport("George Bush Intercontinental Airport", "Houston, TX, USA", "IAH", 0));
      airports.emplace(1, Airport("Amsterdam Airport Schiphol", "Amsterdam, Netherlands", "AMS", 1));
      airports.emplace(2, Airport("Dubai International Airport", "Dubai, UAE","DXB", 2));
      airports.emplace(3, Airport("Toronto Pearson International Airport", "Toronto, ON, Canada", "YYZ", 3));
      airports.emplace(4, Airport("Mexico City International Aiport", "Mexico City, Mexico", "MEX", 4));
      airports.emplace(5, Airport("Cairo International Aiport", "Cairo, Egypt", "CAI", 5));
      airports.emplace(6, Airport("Frankfurt Airport", "Frankfurt, Germany", "FRA", 6));
      airports.emplace(7, Airport("John F. Kennedy International Airport", "New York City, NY, USA", "JFK", 7));
      airports.emplace(8, Airport("Heathrow Airport", "London, UK", "LHR", 8));
      airports.emplace(9, Airport("Los Angeles International Airport", "Los Angeles, CA, USA", "LAX", 9));
      airports.emplace(10, Airport("Narita International Airport", "Tokyo-Narita, Japan", "NRT", 10));
      airports.emplace(11, Airport("Tokyo International Airport", "Tokyo, Japan", "HND", 11));
      airports.emplace(12, Airport("Shanghai Pudong International Airport", "Shanghai, China", "PVG", 12));
      airports.emplace(13, Airport("Tan Son Nhat International Airport", "Saigon (HCMC), Vietnam", "SGN", 13));
      airports.emplace(14, Airport("Suvarnabhumi Airport", "Bangkok, Thailand", "BKK", 14));
      airports.emplace(15, Airport("Singapore Changi Airport", "Singapore", "SIN", 15));
      airports.emplace(16, Airport("Indira Gandhi International Airport", "Delhi, India", "DEL", 16));
      airports.emplace(17, Airport("Istanbul Airport", "Istanbul, Turkey", "IST", 17));
      airports.emplace(18, Airport("Beirut–Rafic Hariri International Airport", "Beirut, Lebanon", "BEY", 18));
      airports.emplace(19, Airport("Leonardo da Vinci–Fiumicino Airport", "Rome, Italy", "FCO", 19));
      airports.emplace(20, Airport("Paris Charles de Gaulle Airport", "Paris, France", "CDG", 20));
      airports.emplace(21,Airport("Josep Tarradellas Barcelona-El Prat Airport", "Barcelona, Spain", "BCN", 21));
      airports.emplace(22, Airport("Arturo Merino Benítez Airport", "Santiago, Chile", "SCL", 22));
      airports.emplace(23,Airport("Rio de Janeiro/Galeão International Airport", "Rio de Janeiro, Brazil", "GIG", 23));      
    }
};