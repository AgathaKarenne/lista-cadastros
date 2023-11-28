Cadastro-usuario:
Estrutura do Usuário: Eu defino uma estrutura chamada Usuario para representar as informações de cada usuário. A estrutura contém campos como id, nome, email, sexo, endereco, altura e vacina.
Esses campos armazenem informações como identificação do usuário, nome, endereço de e-mail, sexo, endereço, altura e estado de vacinação.

Protótipos de recursos: declara protótipos de recursos que serão implementados posteriormente.
Essas funções incluem clearInputBuffer para limpar o buffer de entrada, validarEmail para verificar se um e-mail é válido, e funções para cadastrar, imprimir, buscar, editar e excluir usuários.

Loop do Menu: Dentro do loop principal (do-while), eu exibo um menu para o usuário com opções numeradas de 0 a 5, representando diferentes funcionalidades do programa.
Os usuários podem selecionar uma opção inserindo o número correspondente.

Switch-Case para opções: Eu uso Switch-Case para executar funções que correspondem às opções que o usuário seleciona.
As opções incluem registrar um novo usuário, imprimir uma lista de usuários, procurar um usuário por e-mail, editar um usuário, excluir um usuário ou sair do programa.

Função para Limpar o Buffer de Entrada: A função clearInputBuffer é utilizada para limpar o buffer de entrada, garantindo que não haja caracteres indesejados pendentes.

Função para Validar E-mail: A função validarEmail verifica se um e-mail contém o caractere '@'. Se sim, o e-mail é considerado válido; caso contrário, o usuário será solicitado a digitá-lo novamente.

Função para Cadastrar Usuário: A função cadastrar solicita informações ao usuário para preencher os campos da estrutura Usuario.
Antes de cadastrar o e-mail, é feita uma validação usando a função validarEmail.

Função para Imprimir Lista de Usuários: A função imprimir exibe na tela as informações de todos os usuários cadastrados.

Função de pesquisar usuários por e-mail:
A função searchEmail permite que os usuários pesquisem um usuário específico usando seu endereço de e-mail.

Editar função do usuário:
A função de edição permite editar as informações de um usuário específico com base no ID fornecido pelo usuário.

Excluir função do usuário:
A função de exclusão permite que os usuários excluam usuários com base no ID fornecido.

Plano concluído:
O programa continua em execução até que o usuário selecione a opção “0” para sair. Ao sair, é exibida uma mensagem indicando que o programa foi finalizado.

OBS: QUANDO ESCREVER O NOME EMBAIXO IRA RETORNAR A MENSAGEM "EMAIL INVALIDO TENTE NOVAMENTE" POIS O NOME NAO TEM O CARACTERE '@' NAO SEI COMO RESOLVER ESSE PROBLEMA



