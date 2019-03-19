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

3. Adicione os recursos da SDK no seu projeto através dos **Embedded Binaries**:
<img src="https://github.com/Getmo-Inc/SmartpushSDKiOS/blob/master/Tutorial/embedded.png" width="500">
- Selecione os 3 itens:
<img src="https://github.com/Getmo-Inc/SmartpushSDKiOS/blob/master/Tutorial/libs_choose.png" width="500">

<br>

4. Agora precisamos configurar o **Bundle Id** e a **assinatura** do seu app nos **App Extensions** da SDK:
- Selecione o arquivo **SmartpushSDK.xcodeproj** e depois o target **SmartpushNotificationExtension**.
- Agora substitua apenas o **YOUR-BUNDLE-ID** pelo **Bundle Id** do seu app. Exemplo **com.MyApp.SmartpushNotificationExtension**.
- Configure a assinatura do **App Extension** conforme o seu app.
- Repita o procedimento para o target **SmartpushNotificationContent**.
![](https://github.com/Getmo-Inc/SmartpushSDKiOS/blob/master/Tutorial/extension.png)

<br>

5. Outra coisa muito importante, é fazer a ligação do seu app com os **App Extensions** da SDK. Para isso vá até o menu de **Capablities** do seu app, habilite o **App Groups**, crie uma nova chave e deixa-a marcada. Repida o processo para o **SmartpushNotificationExtension** e para o **SmartpushNotificationContent**:
![](https://github.com/Getmo-Inc/SmartpushSDKiOS/blob/master/Tutorial/app_group.png)

<br>

6. Caso sua aplicação seja em Swift, utilize um **Bridging-Header** para realizar a integração com o framework.
Clique [aqui](https://developer.apple.com/library/content/documentation/Swift/Conceptual/BuildingCocoaApps/MixandMatch.html) para mais informações.

<br>

7. No arquivo **info.plist** do seu projeto adicione as seguintes chaves e seus respectivos valores:
- **SMARTPUSH_DevKey**
- **SMARTPUSH_AppKey**
- **SMARTPUSH_AppGroupKey**: Chave criada no **App Groups**
**Observação**: Caso não possua esses códigos envie um email para suporte@getmo.com.br

- **SMARTPUSH_HitURL** (optional) - URL para receber hits de click e
recebimento; 
- **SMARTPUSH_UseUserLocation** (optional) - Atribuir valor "NO" somente para desabilitar o serviço de geolocalização;

<br>

8. No arquivo **UIApplicationDelegate** implemente o delegate **SmartpushSDKDelegate**.

<br>

9. Ainda no arquivo **UIApplicationDelegate** adicione o código abaixo no corpo do método **didFinishLaunchingWithOptions**:

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

10. Ainda no arquivo **UIApplicationDelegate** adicione o código abaixo no corpo do método **didFailToRegisterForRemoteNotificationsWithError**:

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

11. Ainda no arquivo **UIApplicationDelegate** adicione o código abaixo no corpo do método **didRegisterForRemoteNotificationsWithDeviceToken**:

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

12. Ainda no arquivo **UIApplicationDelegate** adicione o código abaixo no corpo do método **didReceiveRemoteNotification**:

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

13. Ainda no arquivo **UIApplicationDelegate**, para compatibilidade como iOS8+, adicione o código abaixo no corpo do método **didRegisterUserNotificationSettings**:

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

14. Para capturar e tratar as mensagens push recebidas, adicione o código no corpo do método **onPushAccepted** no arquivo **UIApplicationDelegate**. Este método será chamado sempre que uma notificação for recebida ou quando o aplicativo for aberto ao clicar em uma notificação:

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

15. Para que seu aplicativo receba as notificações pela central do iOS enquanto estiver em primeiro plano, importe **UserNotifications** e adicione o código no corpo do método **UIApplicationDelegate** no arquivo **UIApplicationDelegate**.

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

Para definir uma TAG de **String**, ou remove-la utilize o método abaixo:

#### Objective-C
```
[[SmartpushSDK sharedInstance]setString:@"value" forTag:@"key"];
[[SmartpushSDK sharedInstance]delStringTag:@"key"];
```

#### Swift 4
```
SmartpushSDK.sharedInstance().setString("value", forTag: "key")
SmartpushSDK.sharedInstance().delStringTag(key)
```  
Exitem **5** tipos de TAGs que podem ser definidas:
- **String**
- **Number**
- **Boolean**
- **Date**
- **Array**

<br>

### Blacklist
A SDK provê mecanismos para que os usuários possam cancelar/ativar o recebimento de mensagens push. Para isso utilize o método abaixo:

#### Objective-C
```
[[SmartpushSDK sharedInstance]blockUser:true];
```

#### Swift 4
```
SmartpushSDK.sharedInstance().blockUser(true)
```  

Para cancelar/ativar o recebimento de mensagens push, forneça um meio para que o usuário possa informar isso dentro do seu app. 

<br>

### Nearzones
A SDK provê mecanismos para que possam ser disparadas campanhas de mensagens push quando os usuários entrarem em regiões específicas.

Para monitorar e permitir o envio de mensagens push quando seus usuários ingressarem em determinadas áreas, utilize o método abaixo:

#### Objective-C
```
[[SmartpushSDK sharedInstance]nearestZoneWithLatitude:0.0 andLongitude:0.0];
```

#### Swift 4
```
SmartpushSDK.sharedInstance().nearestZone(withLatitude: 0.0, andLongitude: 0.0)
```  

<br>

## <a name="remove_old_sdk"></a>Removendo antiga SDK
Para remover a antiga SDK que utilizava o arquivo **.framework**, selecione **SmartpushSDK.framework** no seu projeto e **delete-o** movendo para a lixeira.

<img src="https://github.com/Getmo-Inc/SmartpushSDKiOS/blob/master/Tutorial/remove_old.png" width="400">
