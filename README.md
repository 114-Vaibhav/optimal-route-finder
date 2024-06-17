# Optimal Route Finder

## Project Description
The Optimal Route Finder is a C++ application designed to calculate the shortest and most efficient route between cities, incorporating multiple stops. It utilizes Dijkstra's algorithm to determine the optimal path and distance, providing users with clear and precise routing solutions.

## Features
- **Optimal Route Calculation**: Determines the shortest path between cities, including multiple intermediate stops.
- **Graph Construction**: Builds and analyzes weighted undirected graphs for accurate route calculations.
- **Algorithm Implementation**: Uses Dijkstra's algorithm for efficient pathfinding in a weighted graph.
- **User Interface**: Provides an interactive console-based interface for inputting routes, stops, and distances.
- **Path Reconstruction**: Displays the optimal path and distance from the source to the destination.
- **Error Handling**: Ensures accurate input processing and reliable route calculations.

## Installation
To compile and run the Optimal Route Finder, ensure you have a C++ compiler installed. Follow these steps:

1. Clone the repository:
   ```sh
   git clone https://github.com/114-vaibhav/optimal-route-finder.git
   ```
2. Navigate to the project directory:
   ```sh
   cd optimal-route-finder
   ```
3. Compile the code:
   ```sh
   g++ -o optimal_route_finder main.cpp
   ```
4. Run the application:
   ```sh
   ./optimal_route_finder
   ```

## Usage
1. **Enter the source city** when prompted.
2. **Enter the destination city** when prompted.
3. **Specify the number of intermediate stops** between the source and destination.
4. **Enter the names of the intermediate cities/stops**.
5. **Input the distances** between the specified cities as prompted.
6. **View the shortest path and distance** from the source to each city, including the specified destination.

## Example
```sh
Enter the source: A
Enter the destination: D
Enter the number of main stops/cities between source and destination: 2
Enter the 1th city/stop: B
Enter the 2th city/stop: C

Enter the distance between A and B if exist, else 0
