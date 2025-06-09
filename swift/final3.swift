 //
//  ContentView.swift
//  Shared
//
//  Created by NDHU_CSIE on 2025/6/9.
//

import SwiftUI

// 定義聯絡人資料模型
class Prospect: Identifiable, Codable, ObservableObject {
    var id = UUID()
    var name = "Anonymous"
    var emailAddress = ""
    var hobby = ""
    var isContacted = false
}

// 聯絡人列表的資料來源
class Prospects: ObservableObject {
    @Published var people: [Prospect]
    
    init() {
        people = []
    }
}

// 個人資料頁面
struct MeView: View {
    var body: some View {
        Text("Hello, World")
    }
}

// 主視圖
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

// 聯絡人列表視圖
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
                // 新增聯絡人表單
                Form {
                    Section(header: Text("Add New Contact")) {
                        TextField("姓名", text: $name)
                        TextField("電子郵件", text: $emailAddress)
                        
                        // 興趣橫向選擇器
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
                            
                            // 清空輸入欄位
                            name = ""
                            emailAddress = ""
                            selectedHobby = "健身"
                            isContacted = false
                        }
                    }
                }
                
                // 顯示聯絡人列表
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
    
    // 視圖標題
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
    
    // 根據篩選條件過濾聯絡人
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

// 預覽
struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
