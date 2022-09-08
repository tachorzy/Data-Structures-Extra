/*In this extra, I'm using Dijkstra's Shortest Path to figure out the shortest connection (in miles) between airports. More is explained in the comments throughout this program.

Also, this program highlights one of the pitfalls of Dijkstra's Algorithm. It has no consideration for direction. So this program ends actually up taking you north, south, east and west in one trip. When there's really a better path. So instead of having one simple layover lets e.g. IAH to Heathrow to Cairo, it'll take you several short legs.

This is a heafty one! So I hope you enjoy it. Thanks for a wonderful Semester ~ Tariq.
*/

#include <iostream>
#include <list>
#include <map>
#include "Graph.h"

int main() {
  //check out the AirportData class this is where we get a map of all the Airpot Objects.
  AirportData* ad = new AirportData;
  ad->fill();

  Graph* g = new Graph(24);
  g->build(); //builds the graph, creates the edges between all of the airports (24 of them).

  int menuInput, src, dest;
  do{
    cout << "Welcome to SkyCrammer\nWhere we connect you to the world's greatest destinations. Find quick flights with excessive layovers through our search engine. Powered by Dijkstra's Algorithm, SkyCrammer will send you in all sorts of directions. With one quick tap of a button we'll get you to you need to be, and to where you dont need to be. (Note: we have no official affiliations with SkyScanner).\n" << endl;

    cout << "Choose a City of Origin:\n(press 1-24)\n1.Houston, USA\n2. Amsterdam, the Netherlands\n3. Dubai, UAE\n4. Toronto, Canada\n5. Mexico City, Mexico\n6. Cairo, Egypt\n7. Frankfurt, Germany\n8. New York City, USA\n9. London, UK\n10. Los Angeles, USA\n11. Tokyo-Narita, Japan\n12. Tokyo-Haneda, Japan\n13. Shanghai, China\n14. Saigon (HCMC), Vietnam\n15. Bangkok, Thailand\n16. Singapore, Singapore\n17. Delhi, India\n18. Istanbul, Turkey\n19. Beirut, Lebanon\n20. Rome, Italy\n21. Paris, France\n22. Barcelona, Spain\n23. Santiago, Chile\n24. Rio de Janeiro, Brazil\n\n0. To Exit the Menu\n" << endl;
    
    cin >> src;

    cout << "Choose your Destination:\n1.Houston, USA\n2. Amsterdam, the Netherlands\n3. Dubai, UAE\n4. Toronto, Canada\n5. Mexico City, Mexico\n6. Cairo, Egypt\n7. Frankfurt, Germany\n8. New York City, USA\n9. London, UK\n10. Los Angeles, USA\n11. Tokyo-Narita, Japan\n12. Tokyo-Haneda, Japan\n13. Shanghai, China\n14. Saigon (HCMC), Vietnam\n15. Bangkok, Thailand\n16. Singapore, Singapore\n17. Delhi, India\n18. Istanbul, Turkey\n19. Beirut, Lebanon\n20. Rome, Italy\n21. Paris, France\n22. Barcelona, Spain\n23. Santiago, Chile\n24. Rio de Janeiro, Brazil" << endl;

    cin >> dest;

    cout << "\nFinding the shortest path...\n" << endl;

    cout << g->shortestPath(src-1, dest-1, ad->airports) << endl;
    cout << endl;
    
  }while(src != 0 || dest != 0);
} 
