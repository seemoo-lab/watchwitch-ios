import SwiftUI
import Network

struct ContentView: View {

    @State private var targetIP: String = ""
    @State private var transitKey: String = ""
    @ObservedObject private var prefs = Preferences()

    func forceReroute() {
        prefs.trigger()
    }

    func updateIP() {
        let ipStr = targetIP

        NSLog("WWitchC: updateIP to %@", ipStr)

        let components = ipStr.split(separator: ".")

        if(components.count != 4) {
            return
        }

        let b0 = UInt(String(components[0]))!
        let b1 = UInt(String(components[1]))!
        let b2 = UInt(String(components[2]))!
        let b3 = UInt(String(components[3]))!

        let ip = (b0 << 24) | (b1 << 16) | (b2 << 8) | b3

        NSLog("WWitchC: computed ip %#010x", ip)

        prefs.setTargetIp(ip: ip)
        prefs.hostUDP = NWEndpoint.Host(ipStr)
    }

    func sendKeys() {
        prefs.triggerSendKeys(userTransitKey: transitKey)
    }

    var body: some View {
        VStack {
            Spacer()
            VStack {
                Text("🧙‍♀️").font(.system(size: 50, weight: .light, design: .serif))
                Text("WatchWitch").padding(5)
                Text(prefs.startTime).italic()
            }
            Spacer()
            Toggle("Override WiFi Address Updates", isOn: Binding(
                get: { prefs.rerouteEnabled },
                set: { newValue in
                    withAnimation {
                        prefs.setRerouteState(state: newValue)
                    }
                }
            )).padding(5)
            Button("Force Update WiFi Address", action: forceReroute).padding(5)
            Divider().padding(12)
            TextField("Target IP", text: $targetIP).padding(5)
            Button("Set Target IP", action: updateIP).padding(5)
            Divider().padding(12)
            Text("Transit Encryption Secret").padding(5)
            TextField("default/unchanged", text: $transitKey).padding(5)
            Button("Send Keys", action: sendKeys).padding(5)
            Spacer()
        }.padding()
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
