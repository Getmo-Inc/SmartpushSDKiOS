# SmartpushSDK iOS
## Instalação
**Obs:** Caso seu projeto já utilize SDK através do **.framework**, é necessário [remover-lo](#remove_old_sdk) antes de continuar.
1. Adicione este projeto como Submodulo de seu projeto Git, ou faça [Download](https://github.com/Getmo-Inc/SmartpushSDKiOS/archive/master.zip).
```
    $ git submodule add https://github.com/Getmo-Inc/SmartpushSDKiOS.git
```
<br>

2. Abra a pasta **SmartpushSDKiOS** e arraste para dentro do seu projeto o arquivo **SmartpushSDK.xcodeproj**.
![](https://github.com/Getmo-Inc/SmartpushSDKiOS/blob/master/Tutorial/import_project.png)

<br>

3. Agora precisamos configurar o **Bundle Id** e a **assinatura** do seu app nos **App Extensions** da SDK:
- Selecione o arquivo **SmartpushSDK.xcodeproj** e depois o target **SmartpushNotificationExtension**.
- Agora substitua apenas o **YOUR-BUNDLE-ID** pelo **Bundle Id** do seu app. Exemplo **com.MyApp.SmartpushNotificationExtension**.
- Configure a assinatura do **App Extension** conforme o seu app.
- Repita o procedimento para o target **SmartpushNotificationContent**.
![](https://github.com/Getmo-Inc/SmartpushSDKiOS/blob/master/Tutorial/extension.png)

<br>

4. Caso sua aplicação seja em Swift, utilize um **Bridging-Header** para realizar a integração com o framework.
Clique [aqui](https://developer.apple.com/library/content/documentation/Swift/Conceptual/BuildingCocoaApps/MixandMatch.html) para mais informações.

<br>

5. No arquivo **info.plist** do seu projeto adicione as seguintes chaves e seus respectivos valores:
- **SMARTPUSH_DevKey**
- **SMARTPUSH_AppKey**
- **SMARTPUSH_HitURL** (optional) - URL para receber hits de click e
recebimento;  
**Observação**: Caso não possua esses códigos envie um email para suporte@getmo.com.br

<br>

6. Ainda no arquivo **info.plist** adicione o código abaixo para liberar a comunicação com a nossa API.
```
<key>NSAppTransportSecurity</key>
<dict>
    <key>NSAllowsArbitraryLoads</key>
    <false/>
    <key>NSExceptionDomains</key>
    <dict>
        <key>api.getmo.com.br</key>
        <dict>
            <key>NSIncludesSubdomains</key>
            <true/>
            <key>NSTemporaryExceptionAllowsInsecureHTTPLoads</key>
            <true/>
            <key>NSTemporaryExceptionMinimumTLSVersion</key>
            <string>TLSv1.1</string> </dict>
    </dict>
</dict>
```

<br>

7. No arquivo **UIApplicationDelegate** implemente o delegate **SmartpushSDKDelegate**.

<br>

8. Ainda no arquivo **UIApplicationDelegate** adicione o código abaixo no corpo do método **didFinishLaunchingWithOptions**:

#### Objective-C
```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    //-----------SMARTPUSH SECTION-----------
    SmartpushSDK *shared = [SmartpushSDK sharedInstance];
    [shared setDelegate:self];
    [shared didFinishLaunchingWithOptions:launchOptions];
    [shared registerForPushNotifications];

    return YES;
}
```

#### Swift 4
```
func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {

    //-----------SMARTPUSH SECTION-----------
    let shared = SmartpushSDK.sharedInstance()
    shared?.delegate = self
    shared?.didFinishLaunching(options: launchOptions)
    shared?.registerForPushNotifications()

    return true
}
```

<br>

9. Ainda no arquivo **UIApplicationDelegate** adicione o código abaixo no corpo do método **didFailToRegisterForRemoteNotificationsWithError**:

#### Objective-C
```
- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
    [[SmartpushSDK sharedInstance] didFailToRegisterForRemoteNotificationsWithError:error];
}
```

#### Swift 4
```
func application(_ application: UIApplication, didFailToRegisterForRemoteNotificationsWithError error:Error) {
    SmartpushSDK.sharedInstance().didFailToRegisterForRemoteNotificationsWithError(error)
}
```

<br>

10. Ainda no arquivo **UIApplicationDelegate** adicione o código abaixo no corpo do método **didRegisterForRemoteNotificationsWithDeviceToken**:

#### Objective-C
```
- (void)application:(UIApplication*)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken {
    [[SmartpushSDK sharedInstance] didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
}
```

#### Swift 4
```
func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
    SmartpushSDK.sharedInstance().didRegisterForRemoteNotifications(withDeviceToken: deviceToken)
}
```

<br>

11. Ainda no arquivo **UIApplicationDelegate** adicione o código abaixo no corpo do método **didReceiveRemoteNotification**:

#### Objective-C
```
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
    [[SmartpushSDK sharedInstance] didReceiveRemoteNotification:userInfo];
}
```

#### Swift 4
```
func application(_ application: UIApplication, didReceiveRemoteNotification userInfo: [AnyHashable: Any]) {
    SmartpushSDK.sharedInstance().didReceiveRemoteNotification(userInfo)
}
```

<br>

12. Ainda no arquivo **UIApplicationDelegate**, para compatibilidade como iOS8+, adicione o código abaixo no corpo do método **didRegisterUserNotificationSettings**:

#### Objective-C
```
- (void)application:(UIApplication *)application didRegisterUserNotificationSettings: (UIUserNotificationSettings *)notificationSettings {
    [[SmartpushSDK sharedInstance] didRegisterUserNotificationSettings:notificationSettings];
}
```

#### Swift 4
```
func application(_ application: UIApplication, didRegister notificationSettings: UIUserNotificationSettings) {
    SmartpushSDK.sharedInstance().didRegister(notificationSettings)
}
```

<br>

13. Para capturar e tratar as mensagens push recebidas, adicione o código no corpo do método **onPushAccepted** no arquivo **UIApplicationDelegate**. Este método será chamado sempre que uma notificação for recebida ou quando o aplicativo for aberto ao clicar em uma notificação:

#### Objective-C
```
- (void)onPushAccepted:(NSDictionary *)push andOpenFromPush:(BOOL) openFromPush {
    NSLog(@"Push: %@", push);
}

- (void)onPushAccepted:(NSDictionary *)push andOpenFromPush:(BOOL) openFromPush withUri:(NSString*) uri {
    NSLog(@"Push: %@", push);
}
```

#### Swift 4
```
func onPushAccepted(_ push: [AnyHashable: Any]!, andOpenFromPush openFromPush: Bool) {
    print("Push: \(push)")
}

func onPushAccepted(_ push: [AnyHashable : Any]!, andOpenFromPush openFromPush: Bool, withUri uri: String!) {
    print("Push: \(push)")
}
```

<br>

### Melhorias para o iOS 10+

14. Para que seu aplicativo receba as notificações pela central do iOS enquanto estiver em primeiro plano, adicione o código no corpo do método **UIApplicationDelegate** no arquivo **UIApplicationDelegate**.

#### Objective-C
```
- (void) userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions))completionHandler  NS_AVAILABLE_IOS(10.0) {
    completionHandler(UNAuthorizationOptionAlert | UNAuthorizationOptionBadge | UNAuthorizationOptionSound);
}
```

#### Swift 4
```
@available(iOS 10.0, *)
func userNotificationCenter(_ center: UNUserNotificationCenter, willPresent notification: UNNotification, withCompletionHandler completionHandler: @escaping (UNNotificationPresentationOptions) -> Void) {
    completionHandler([.alert, .badge, .sound])
}
```


**Pronto! A SDK SMARTPUSH está integrada a sua app! Sua app está pronta para receber mensagens push. Simples, não?**

<br>

## Gerenciando TAGs, Blacklist e Nearzones
### TAGs
A SDK provê mecanismos para que as apps possam criar e salvar tags, que depois serão utilizadas na filtragem dos conjuntos para envio direcionado de mensagens push através da API REST.

Para configurar uma TAG utilize o método disponível na classe **SmartpushSDK.setTag**. Este método recebe como parâmetros uma chave e um valor.

### Blacklist
A SDK provê mecanismos para que os usuários possam cancelar/ativar o recebimento de mensagens push.

Para cancelar/ativar o recebimento de mensagens push forneça um meio para que o usuário possa utilizar o método disponível na classe **SmartpushSDK.blacklist**. Este método recebe como parâmetros um boolean.
### Nearzones
A SDK provê mecanismos para que possam ser disparadas campanhas de mensagens push quando os usuários entrarem em regiões específicas.

Para monitorar e permitir o envio de mensagens push quando seus usuários ingressarem em determinadas áreas, utilize o método disponível na classe **SmartpushSDK.nearzones**. Este método recebe como parâmetros a latitude e a longitude.

<br>

## <a name="remove_old_sdk"></a>Removendo antiga SDK
Para remover a antiga SDK que utilizava o arquivo **.framework**, selecione **SmartpushSDK.framework** no seu projeto e **delete-o** movendo para a lixeira.

![](https://github.com/Getmo-Inc/SmartpushSDKiOS/blob/master/Tutorial/remove_old.png)
