//
//  ContentView.swift
//  Shared
//
//  Created by NDHU_CSIE on 2025/6/9.
//

import SwiftUI

class Prospect: Identifiable, Codable, ObservableObject {
    var id = UUID()
    var name = "Anonymous"
    var emailAddress = ""
    var hobby = ""
    var isContacted = false
}


class Prospects: ObservableObject {
    @Published var people: [Prospect]
    
    init() {
        people = []
    }
}

struct MeView: View {
    var body: some View {
        Text("Hello, World")
    }
}


struct ContentView: View {
    @StateObject var prospects = Prospects()
    
    var body: some View {
        TabView {
            ProspectsView(filter: .none)
                .tabItem {
                    Label("Everyone", systemImage: "person.3")
                }
            ProspectsView(filter: .contacted)
                .tabItem {
                    Label("Contacted", systemImage: "checkmark.circle")
                }
            ProspectsView(filter: .uncontacted)
                .tabItem {
                    Label("Uncontacted", systemImage: "questionmark.diamond")
                }
            MeView()
                .tabItem {
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
    
    @State private var name = ""
    @State private var emailAddress = ""
    @State private var selectedHobby = "Reading"
    @State private var isContacted = false
    
    let hobbies = ["健身", "電影", "游泳", "打球", "其他"]
    
    var body: some View {
        NavigationView {
            VStack {
                
                Form {
                    Section(header: Text("Add New Contact")) {
                        TextField("姓名", text: $name)
                        TextField("電子郵件", text: $emailAddress)
                        
                        
                        Picker("興趣", selection: $selectedHobby) {
                            ForEach(hobbies, id: \.self) { hobby in
                                Text(hobby)
                            }
                        }
                        .pickerStyle(SegmentedPickerStyle())
                        
                        
                        
                        Toggle("已聯絡", isOn: $isContacted)
                        
                        Button("Add") {
                            let newProspect = Prospect()
                            newProspect.name = name
                            newProspect.emailAddress = emailAddress
                            newProspect.hobby = selectedHobby
                            newProspect.isContacted = isContacted
                            prospects.people.append(newProspect)
                            
                            
                            name = ""
                            emailAddress = ""
                            selectedHobby = "健身"
                            isContacted = false
                        }
                    }
                }
                
                
                List {
                    ForEach(filteredProspects) { prospect in
                        VStack(alignment: .leading, spacing: 5) {
                            Text(prospect.name)
                                .font(.headline)
                            Text(prospect.emailAddress)
                                .foregroundColor(.secondary)
                            Text("Hobby: \(prospect.hobby)")
                                .foregroundColor(.secondary)
                            Text("Contacted: \(prospect.isContacted ? "Yes" : "No")")
                                .foregroundColor(.secondary)
                        }
                        .padding(.vertical, 5)
                    }
                }
                .navigationTitle(title)
            }
        }
    }
    
    var title: String {
        switch filter {
        case .none:
            return "Everyone"
        case .contacted:
            return "Contacted People"
        case .uncontacted:
            return "Uncontacted People"
        }
    }
    
    var filteredProspects: [Prospect] {
        switch filter {
        case .none:
            return prospects.people
        case .contacted:
            return prospects.people.filter { $0.isContacted }
        case .uncontacted:
            return prospects.people.filter { !$0.isContacted }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
