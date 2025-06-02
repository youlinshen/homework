import SwiftUI

class Prospect: Identifiable, Codable {
    var id = UUID()
    var name = "Anonymous"
    var emailAddress = ""
    var isContacted = false
}

class Prospects: ObservableObject {
    @Published var people: [Prospect]
    init(){
        people = []
    }
}

struct MeView: View {
    var body: some View{
        Text("Hello, World")
    }
}

struct MeView_Previews: PreviewProvider{
    static var previews: some View{
        MeView()
    }
}


struct ContentView: View {
    @StateObject var prospects = Prospects()
    var body: some View {
        TabView{
            ProspectsView(filter: .none)
                .tabItem{
                    Label("Everyone", systemImage: "person.3")
                }
            ProspectsView(filter: .contacted)
                .tabItem{
                    Label("Contacted", systemImage: "checkmark.circle")
                }
            ProspectsView(filter: .uncontacted)
                .tabItem{
                    Label("Uncontacted", systemImage: "questionmark.diamond")
                }
            MeView()
                .tabItem{
                    Label("Me", systemImage: "person.crop.square")
                }
        }
        .environmentObject(prospects)
    }
}


struct ProspectsView: View {
    enum FilterType {
        case none, contacted, uncontacted
    }
    @EnvironmentObject var prospects: Prospects
    let filter: FilterType
    var body: some View{
        NavigationView{
            VStack{
                HStack{
                    Button {
                        let prospect = Prospect()
                        prospect.name = "Jiann-Ming"
                        prospect.emailAddress = "gms.ndhu"
                        prospect.isContacted = false
                        prospects.people.append(prospect)
                    } label: {
                        Label("Scan", systemImage: "qrcode.viewfinder")
                    }
                    Button {
                        let prospect = Prospect()
                        prospect.name = "Contacted"
                        prospect.emailAddress = "gms.ndhu"
                        prospect.isContacted = true
                        prospects.people.append(prospect)
                    } label: {
                        Label("Contacted", systemImage: "person.fill")
                    }
                }
                List {
                    ForEach(filteredProspects) {prospect in
                        VStack(alignment: .leading){
                            Text(prospect.name)
                                .font(.headline)
                            Text(prospect.emailAddress)
                                .foregroundColor(.secondary)
                        }
                        
                    }
                }
                .navigationTitle(title)
            }
            
        }
    }
    var title: String{
        switch filter {
        case .none:
            return "Everyone"
        case .contacted:
            return "Contacted people"
        case .uncontacted:
            return "Uncontacted people"
        }
    }
    var filteredProspects: [Prospect] {
        switch filter {
        case .none:
            return prospects.people
        case .contacted:
            return prospects.people.filter
                {$0.isContacted}
        case .uncontacted:
            return prospects.people.filter
                {!$0.isContacted}
        }
    }
}

struct ProspectsView_Previews: PreviewProvider {
    static var previews: some View{
        ProspectsView(filter: .none)
            .environmentObject(Prospects())
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
