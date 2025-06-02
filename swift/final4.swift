import SwiftUI
import MapKit


struct Location: Identifiable {
    let id = UUID()
    let name: String
    let coordinate: CLLocationCoordinate2D
}

struct ContentView: View {
    @State private var mapRegion = MKCoordinateRegion(center: CLLocationCoordinate2D(latitude: 23.98, longitude: 121.60), span: MKCoordinateSpan(latitudeDelta: 0.2, longitudeDelta: 0.2))
    
    var body: some View {
        let locations = [
            Location(name: "火車站", coordinate: CLLocationCoordinate2D(latitude: 23.9927, longitude: 121.6014)),
            Location(name: "吉安農會", coordinate: CLLocationCoordinate2D(latitude: 23.9720, longitude: 121.5626))
        ]
        
        NavigationView {
            Map(coordinateRegion: $mapRegion, annotationItems: locations) { location in
                MapAnnotation(coordinate: location.coordinate) {
                    NavigationLink (destination: Text(location.name)
                    ) {
                        Circle()
                            .stroke(Color.red, lineWidth: 3)
                            .frame(width: 22, height: 22)
                    }
                }
            }
            .navigationTitle("Hualien Explorer")
        }
        Text("Hello, World!")
            .padding()
    }
}
