import SwiftUI

// 定义联系人数据模型
class Prospect: Identifiable, Codable {
    var id = UUID()
    var name = "Anonymous"
    var emailAddress = ""
    var hobby = ""
    var isContacted = false
}

// 定义Prospects数据源
class Prospects: ObservableObject {
    @Published var people: [Prospect]
    
    init() {
        people = []
    }
}

// MeView 视图（个人信息视图）
struct MeView: View {
    var body: some View {
        Text("Hello, World")
    }
}

// 个人信息视图预览
struct MeView_Previews: PreviewProvider {
    static var previews: some View {
        MeView()
            .environmentObject(Prospects()) // 传递环境对象
    }
}

// 主视图，包含TabView
struct ContentView: View {
    @StateObject var prospects = Prospects() // 状态对象，管理联系人数据
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
        .environmentObject(prospects) // 传递环境对象给所有子视图
    }
}

// 联系人列表视图
struct ProspectsView: View {
    enum FilterType {
        case none, contacted, uncontacted
    }
    
    @EnvironmentObject var prospects: Prospects
    let filter: FilterType
    
    // 状态变量，存储新联系人输入的内容
    @State private var name = ""
    @State private var emailAddress = ""
    @State private var selectedHobby = "Reading"  // 默认选中兴趣
    @State private var isContacted = false
    
    // 兴趣选项
    let hobbies = ["Reading", "Gaming", "Sports", "Music", "Cooking", "Traveling"]
    
    var body: some View {
        NavigationView {
            VStack {
                // 输入框
                Form {
                    Section(header: Text("Add New Contact")) {
                        TextField("Name", text: $name)
                        TextField("Email", text: $emailAddress)
                        
                        // 兴趣选择器
                        Picker("Hobby", selection: $selectedHobby) {
                            ForEach(hobbies, id: \.self) { hobby in
                                Text(hobby)
                            }
                        }
                        .pickerStyle(MenuPickerStyle())
                        
                        Toggle("Contacted", isOn: $isContacted)
                        
                        Button("Save") {
                            // 保存新联系人到联系人列表
                            let newProspect = Prospect()
                            newProspect.name = name
                            newProspect.emailAddress = emailAddress
                            newProspect.hobby = selectedHobby
                            newProspect.isContacted = isContacted
                            prospects.people.append(newProspect)
                            
                            // 清空输入框
                            name = ""
                            emailAddress = ""
                            selectedHobby = "Reading" // 默认值
                            isContacted = false
                        }
                    }
                }
                
                // 联系人列表
                List {
                    ForEach(filteredProspects) { prospect in
                        VStack(alignment: .leading) {
                            Text(prospect.name)
                                .font(.headline)
                            Text(prospect.emailAddress)
                                .foregroundColor(.secondary)
                            Text("Hobby: \(prospect.hobby)")
                                .foregroundColor(.secondary)
                            Toggle("Contacted", isOn: Binding(
                                get: { prospect.isContacted },
                                set: { newValue in
                                    if let index = prospects.people.firstIndex(where: { $0.id == prospect.id }) {
                                        prospects.people[index].isContacted = newValue
                                    }
                                }
                            ))
                            .toggleStyle(SwitchToggleStyle(tint: .blue))
                        }
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
            return prospects.people.filter { $0.isContacted }
        case .uncontacted:
            return prospects.people.filter { !$0.isContacted }
        }
    }
}

// 联系人列表预览
struct ProspectsView_Previews: PreviewProvider {
    static var previews: some View {
        ProspectsView(filter: .none)
            .environmentObject(Prospects()) // 预览时传递环境对象
    }
}

// 主视图预览
struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
