# SmartpushSDK iOS

# O que são Push Notifications? #

O serviço Apple Push Notification (APNs) é a peça central do recurso de notificações remotas. É um serviço robusto, seguro e altamente eficiente para os desenvolvedores de aplicativos propagarem informações para dispositivos iOS.

# O que as Push Notifications podem fazer? #

* Exibir uma mensagem.
* Tocar um som.
* Fornecer ações com as quais o usuário pode agir com ou sem abrir o aplicativo.
* Mostrar uma imagem ou outro tipo de mídia, até mesmo vídeos.
* Solicitar ao aplicativo para realizar alguma ação em segundo plano.

# Itens necessários antes de começar a configurar #

* Um dispositivo iOS de verdade, infelizmente as push notifications não funcionam no simulador.
* Programa de desenvolvedores da Apple, é necessário ter uma conta de desenvolvedor.
* É necessário criar uma conta no portal https://admin.getmo.com.br, é atrávez do portal que os push chegarão aos dispositivos.

## <a name="configurar_apns"></a> Configuração do APNS e implementação inicial passo a passo 

Passo 1: É necessário criar um projeto.

Passo 2: Habilitar o push em Capabilities, setar para ON.
![picture](http://cdn.getmo.com.br/images/tutorial_ios/enable_push.png)

Passo 3: Obtenha o certificado de APNs: acesse sua conta do Apple Dev Member Center e faça o login. Clique em Certificados, IDs e perfis -> Identificadores -> IDs de aplicativo onde você deve ver todos os identificadores do aplicativo, selecione aquele para o qual você está criando notificações . Você verá uma grande lista de serviços de aplicativos disponíveis - as notificações por push devem ser marcadas como configuráveis:
![picture](http://cdn.getmo.com.br/images/tutorial_ios/config_push.png)

Deve haver um botão Editar na parte inferior, clique nele e encontre as notificações por push nessa lista novamente.
![picture](http://cdn.getmo.com.br/images/tutorial_ios/enable_push_step4.png)

O que você precisa é o Certificado SSL de Desenvolvimento, clique no Botão Criar Certificado e siga as instruções para criar um Arquivo CSR. Mantenha o CMD + Space para iniciar o spotlight no seu Mac, escreva Keychain Access e pressione enter para iniciar o App de Acesso às Chaves:
![picture](http://cdn.getmo.com.br/images/tutorial_ios/spotlight_access.png)

Passo 4, por instruções da Apple:

No menu superior em Keychain Access, selecione Keychain Access> Certificate Assistant> Solicitar um certificado de uma autoridade de certificação.
![picture](http://cdn.getmo.com.br/images/tutorial_ios/keychain.png)

Preencha corretamente as Informações do certificado e salve o arquivo .certSigningRequest em um local fácil de encontrar, porque será necessário enviá-lo aqui:
![picture](http://cdn.getmo.com.br/images/tutorial_ios/generate_certificate.png)

Após o upload, você verá essa tela:
![picture](http://cdn.getmo.com.br/images/tutorial_ios/download_cert.png)

Faça o download do certificado gerado, clique duas vezes no arquivo .cer e encontre-o instalado no seu Keychain Access:
![picture](http://cdn.getmo.com.br/images/tutorial_ios/cert_keychain.png)

Neste momento, peço para que guarde o certificado pois precisaremos dele mais tarde para adicionar no portal da SmartPush.

Este processo foi longo, mas vale a pena. Siga estas etapas novamente Certificados, IDs e perfis -> Identificadores -> IDs de aplicativos e você verá que as notificações push estão ativadas para desenvolvimento:
![picture](http://cdn.getmo.com.br/images/tutorial_ios/show_enabled.png)

Agora vamos fazer a instalação da sdk no xcode:
## Instalação
**Obs:** Caso seu projeto já utilize SDK através do **.framework**, é necessário [remover-lo](#remove_old_sdk) antes de continuar.
1. Adicione este projeto como Submodulo de seu projeto Git, ou faça [Download](https://github.com/Getmo-Inc/SmartpushSDKiOS/archive/master.zip).
```
    $ git submodule add https://github.com/Getmo-Inc/SmartpushSDKiOS.git
```
<br>

Se você já tem o projeto acidionado como submodulo do git e precisa fazer update, acesse [aqui](#atualizar_sdk).

2. Abra a pasta **SmartpushSDKiOS** e arraste para dentro do seu projeto o arquivo **SmartpushSDK.xcodeproj**.
![](http://cdn.getmo.com.br/images/tutorial_ios/import_project.png)

<br>

3. Adicione os recursos da SDK no seu projeto através dos **Embedded Binaries**:
<img src="http://cdn.getmo.com.br/images/tutorial_ios/embedded.png" width="500">
- Selecione os 3 itens:
<img src="http://cdn.getmo.com.br/images/tutorial_ios/libs_choose.png" width="500">

<br>

4. Agora precisamos configurar o **Bundle Id** e a **assinatura** do seu app nos **App Extensions** da SDK:
- Selecione o arquivo **SmartpushSDK.xcodeproj** e depois o target **SmartpushNotificationExtension**.
- Agora substitua apenas o **YOUR-BUNDLE-ID** pelo **Bundle Id** do seu app. Exemplo **com.MyApp.SmartpushNotificationExtension**.
- Configure a assinatura do **App Extension** conforme o seu app.
- Repita o procedimento para o target **SmartpushNotificationContent**.
![](http://cdn.getmo.com.br/images/tutorial_ios/extension.png)

<br>

5. Para fazer a ligação do app com as extensions **App Extensions** da SDK é necessário criar um grupo. 

Para criar um grupo, acesse o menu **Capabilities** e clique no botão "+":
<img src="http://cdn.getmo.com.br/images/tutorial_ios/appgroup_plus_button.png" width="500">

Então digite um nome para o grupo, esse será o valor da tag **SMARTPUSH_AppGroupKey**, veremos isso em seguida.
<img src="http://cdn.getmo.com.br/images/tutorial_ios/appgroup_create.png" width="500">

Deixe o grupo marcado e repita o processo para o **SmartpushNotificationExtension** e para o **SmartpushNotificationContent**:
<img src="http://cdn.getmo.com.br/images/tutorial_ios/app_group.png" width="500">

<br>

6. Caso sua aplicação seja em Swift, utilize um **Bridging-Header** para realizar a integração com o framework.
Clique [aqui](https://developer.apple.com/library/content/documentation/Swift/Conceptual/BuildingCocoaApps/MixandMatch.html) para mais informações.

<br>

7. No arquivo **info.plist** do seu projeto adicione as seguintes chaves e seus respectivos valores:
- **SMARTPUSH_DevKey**
- **SMARTPUSH_AppKey**

O app key é encontrado no portal, acessando o menu "Apps".
![](http://cdn.getmo.com.br/images/tutorial_ios/appid_screen.png)

- **SMARTPUSH_AppGroupKey**: Chave criada no **App Groups**

- **SMARTPUSH_HitURL** (optional) - URL para receber hits de click e
recebimento; 
- **SMARTPUSH_UseUserLocation** (optional) - Atribuir valor "NO" somente para desabilitar o serviço de geolocalização;

<br>

Se você ainda não criou os certificados [clique aqui](#configurar_apns)

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

#### Swift
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

#### Swift
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

#### Swift
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

#### Swift
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

#### Swift
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

#### Swift
```
func onPushAccepted(_ push: [AnyHashable: Any]!, andOpenFromPush openFromPush: Bool) {
    print("Push: \(push)")
}

func onPushAccepted(_ push: [AnyHashable : Any]!, andOpenFromPush openFromPush: Bool, withUri uri: String!) {
    print("Push: \(push)")
}
```

<br>

15. Para que seu aplicativo receba as notificações pela central do iOS enquanto estiver em primeiro plano, importe **UserNotifications** e adicione o código no corpo do método **UIApplicationDelegate** no arquivo **UIApplicationDelegate**.

#### Objective-C
```
- (void) userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions))completionHandler  NS_AVAILABLE_IOS(10.0) {
    completionHandler(UNAuthorizationOptionAlert | UNAuthorizationOptionBadge | UNAuthorizationOptionSound);
}
```

#### Swift
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

#### Swift
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

#### Swift
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

#### Swift
```
SmartpushSDK.sharedInstance().nearestZone(withLatitude: 0.0, andLongitude: 0.0)
```  

### Inbox - Acesso as últimas notificações

### Last Notifications
A SDK provê mecanismos para que os usuários possam acessar as últimas notificações através dos métodos abaixo:
O conteúdo do retorno é um objeto do tipo NSData.
```
    //Add observer get last notifications
    NotificationCenter.default.addObserver(self, selector: #selector(self.refreshData), name: NSNotification.Name.SmartpushSDKLastNotificationsObtained, object: nil)

    SmartpushSDK.sharedInstance().requestLastNotifications()

    let data = SmartpushSDK.sharedInstance().getLastNotifications()?.dataResponse!
``` 

### Mark as read
A SDK provê a funcionalidade de marcar uma notificação como lida. O parâmetro necessário é o id do push.

```
    SmartpushSDK.sharedInstance()?.markPush(asRead: obj.pushid)
``` 

### Mark all as read
A SDK provê a funcionalidade de marcar todas as notificações como lidas.

```
    SmartpushSDK.sharedInstance()?.markAllAsRead()
``` 

### Extra content
A SDK provê a funcionalidade acessar o conteúdo extra de uma notificação. Este é um conteúdo livre customizável pelo cliente.
```
    SmartpushSDK.sharedInstance()?.requestExtraContent(for: obj.pushid)
``` 

O último passo é adicionar os certificados no portal:
![picture](http://cdn.getmo.com.br/images/tutorial_ios/certificados_portal.png)

<br>

## <a name="remove_old_sdk"></a>Removendo antiga SDK
Para remover a antiga SDK que utilizava o arquivo **.framework**, selecione **SmartpushSDK.framework** no seu projeto e **delete-o** movendo para a lixeira.

<img src="http://cdn.getmo.com.br/images/tutorial_ios/remove_old.png" width="400">

<br>

## <a name="atualizar_sdk"></a> Atualizar instalação da SDK 
Para atualizar a SDK é necessário fazer o procedimento a seguir:

Execute os comandos
```
    git submodule init
```
seguido por:
```
    git submodule update
```

e então vá para o diretório SmartpushSDKiOS
```
    cd SmartpushSDKiOS
```

e execute o comando
```
    git pull
```

pronto, a SDK está atualizada e agora é só compilar.
 

