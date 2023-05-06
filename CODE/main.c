#include <stdio.h>
#include <stdbool.h>
#define INF 99999999 
void dijkstra(int n, int k, int times[][3], int dist[]) {
    bool visited[n+1];
    for (int i = 1; i <= n; i++) {
        dist[i] = INF; 
        visited[i] = false; 
    }
    dist[k] = 0; 
    for (int i = 1; i <= n; i++) {
        int u = -1; 
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        if (dist[u] == INF) { 
            break;
        }
        visited[u] = true; 
        for (int j = 0; j < times[j][0] != 0; j++) {
            int v = times[j][1], w = times[j][2];
            if (times[j][0] == u && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w; 
            }
        }
    }
}

int networkDelayTime(int times[][3], int timesSize, int n, int k) {
    int dist[n+1];
    dijkstra(n, k, times, dist); 
    int max_dist = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) { 
            return -1;
        }
        max_dist = (dist[i] > max_dist) ? dist[i] : max_dist; 
    }
    return max_dist;
}

int main() {
    int times[][3] = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;
    int min_time = networkDelayTime(times, 3, n, k);
    printf("%d", min_time); 
    return 0;
}