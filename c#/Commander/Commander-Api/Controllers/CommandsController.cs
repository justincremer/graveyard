using System.Collections.Generic;
using AutoMapper;
using Commander.Data;
using Commander.Dtos;
using Commander.Models;
using Microsoft.AspNetCore.JsonPatch;
using Microsoft.AspNetCore.Mvc;

namespace Commander.Controllers
{
    [Route("api/commands")]
    [ApiController]
    public class CommandsController : ControllerBase
    {
        private readonly ICommanderRepo _repository;
        private readonly IMapper _mapper;

        public CommandsController(ICommanderRepo repository, IMapper mapper)
        {
          _repository = repository;
          _mapper = mapper;
        }

        [HttpGet]
        public ActionResult <IEnumerable <CommandReadDto>> GetAllComands() => Ok(_mapper.Map<IEnumerable <CommandReadDto>>(_repository.GetAllCommands()));

        [HttpGet("{id}", Name="GetCommandById")]
        public ActionResult <CommandReadDto> GetCommandById(int id){
          var item = _repository.GetCommandById(id);
          
          if(item != null) 
            return Ok(_mapper.Map<CommandReadDto>(item));
          else 
            return NotFound();
        }

        [HttpPost]
        public ActionResult <CommandReadDto> PostCommand(CommandWriteDto commandWriteDto)
        {
          var commandModel = _mapper.Map<Command>(commandWriteDto);
          _repository.PostCommand(commandModel);
          var commandReadDto = _mapper.Map<CommandReadDto>(commandModel);
                    
          return CreatedAtRoute(nameof(GetCommandById), new {Id = commandReadDto.Id}, commandReadDto);
        }

        [HttpPut("{id}")]
        public ActionResult PutCommand(int id, CommandUpdateDto commandUpdateDto)
        {
          var commandModel = _repository.GetCommandById(id);
          
          if(commandModel == null)
            return NotFound();
          
          _mapper.Map(commandUpdateDto, commandModel);
          _repository.PutCommand(commandModel);
          _repository.SaveChanges();

          return NoContent();
        }

        [HttpPatch("{id}")]
        public ActionResult PatchCommand(int id, JsonPatchDocument<CommandUpdateDto> patchDoc)
        {
          var commandModel = _repository.GetCommandById(id);
          
          if(commandModel == null)
            return NotFound();

          var commandToPatch = _mapper.Map<CommandUpdateDto>(commandModel);
          patchDoc.ApplyTo(commandToPatch, ModelState);

          if(!TryValidateModel(commandToPatch))
            return ValidationProblem(ModelState);

          _mapper.Map(commandToPatch, commandModel);
          _repository.PutCommand(commandModel);
          _repository.SaveChanges();

          return NoContent();
        }

        [HttpDelete("{id}")]
        public ActionResult DeleteCommand(int id)
        {
          var commandModel = _repository.GetCommandById(id);
          
          if(commandModel == null)
            return NotFound();

          _repository.DeleteCommand(commandModel);
          _repository.SaveChanges();

          return NoContent();
        }
    }
}