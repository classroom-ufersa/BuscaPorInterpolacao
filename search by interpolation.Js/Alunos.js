let listaAlunos = [];
let MenuResposiveBtn = document.querySelector("#MenuResposiveBtn");
let Menuresponsive = document.querySelector(".MenuResposive");
let MenuResposiveBtn2 = document.querySelector("#MenuResposiveBtn2");
let Menuresponsive2 = document.querySelector(".MenuResposive2");
let MenuResposiveBtn3 = document.querySelector("#MenuResposiveBtn3");
let Menuresponsive3 = document.querySelector(".MenuResposive3");

MenuResposiveBtn.addEventListener("click", () => {
  MenuResposiveBtn.classList.toggle("fa-xmark");
  Menuresponsive.classList.toggle("open-menu");
});

MenuResposiveBtn2.addEventListener("click", () => {

  MenuResposiveBtn2.classList.toggle("fa-xmark");
  Menuresponsive2.classList.toggle("open-menu");
});

MenuResposiveBtn3.addEventListener("click", () => {

  MenuResposiveBtn3.classList.toggle("fa-xmark");
  Menuresponsive3.classList.toggle("open-menu2");
});



document.getElementById('Cadastrar3').addEventListener('click', imprimirLista);
document.getElementById('Cadastrar4').addEventListener('click', salvarLista);
document.getElementById('Cadastrar5').addEventListener('click', carregarLista);



function cadastrarAluno() {

  const nome = document.getElementById('nome').value;
  const documento = document.getElementById('documento').value;
  const matricula = parseInt(document.getElementById('matricula').value);

  const novoAluno = {
    nome: nome,
    documento: documento,
    matricula: matricula
  };

  listaAlunos.push(novoAluno);

  document.getElementById('nome').value = '';
  document.getElementById('documento').value = '';
  document.getElementById('matricula').value = '';

  alert('Aluno cadastrado com sucesso!');

}

function buscarAlunoMatricula() {
  
  const matricula = parseInt(document.getElementById('pormatricula').value);

      listaAlunos.sort((a, b) => a.matricula - b.matricula);

      let alunoEncontrado = null;
      let inicio = 0;
      let fim = listaAlunos.length - 1;

      while (inicio <= fim) {
        let posicao = Math.floor(inicio + (fim - inicio) / 2);

        if (listaAlunos[posicao].matricula === matricula) {
          alunoEncontrado = listaAlunos[posicao];
          break;
        }

        if (listaAlunos[posicao].matricula < matricula) {
          inicio = posicao + 1;
        } else {
          fim = posicao - 1;
        }
      }

      if (alunoEncontrado != null) {
        alert(`Aluno encontrado: ${alunoEncontrado.nome} - Documento: ${alunoEncontrado.documento} - Matrícula: ${alunoEncontrado.matricula}`);
      } else {
        alert('Aluno não encontrado');
      }

}

function buscarAlunoNome() {
  
  const nome = document.getElementById('pornome').value;

  listaAlunos.sort((a, b) => a.nome.localeCompare(b.nome));

  let alunoEncontrado = null;
  let inicio = 0;
  let fim = listaAlunos.length - 1;

  while (inicio <= fim) {
    let posicao = Math.floor(inicio + (fim - inicio) / 2);

    if (listaAlunos[posicao].nome === nome) {
      alunoEncontrado = listaAlunos[posicao];
      break;
    }

    if (listaAlunos[posicao].nome < nome) {
      inicio = posicao + 1;
    } else {
      fim = posicao - 1;
    }
  }

  if (alunoEncontrado != null) {
    alert(`Aluno encontrado: ${alunoEncontrado.nome} - Documento: ${alunoEncontrado.documento} - Matrícula: ${alunoEncontrado.matricula}`);
  } else {
    alert('Aluno não encontrado');
  }
  
}

function imprimirLista() {
  // Vamos percorrer a lista de alunos e exibir os dados de cada um:
  listaAlunos.sort((a, b) => a.nome.localeCompare(b.nome));
  let mensagem = 'Lista de alunos <br>';
  for (let i = 0; i < listaAlunos.length; i++) {
    mensagem += `${listaAlunos[i].nome}: Documento: ${listaAlunos[i].documento}  Matrícula: ${listaAlunos[i].matricula}<br>`;
  }
  document.querySelector('.open-menu2').innerHTML = mensagem;
}


function salvarLista() {
  const listaAlunosJSON = JSON.stringify(listaAlunos);
  localStorage.setItem('listaAlunos', listaAlunosJSON);
  alert('Lista Salva com Sucesso!');
}

function carregarLista() {
  const listaAlunosJSON = localStorage.getItem('listaAlunos');
  if (listaAlunosJSON) {
    listaAlunos = JSON.parse(listaAlunosJSON);
    alert('Lista Carregada com Sucesso!');
  }
}

function sair() {
  window.close();
}